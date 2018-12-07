#include "PhoneNumber.h"

using namespace std;

PhoneNumber::PhoneNumber()
{
	phoneNumber = "";
	operatorName = "";
}


PhoneNumber::PhoneNumber(string phNumber, string opName)
{
	if (phNumber.size() == 15 && opName == "KomKothaKoiben" || opName == "GrameenPhone" || opName == "Robi" || opName == "Teletalk" || opName == "BanglaLink")
	{
		phoneNumber = phNumber;
		operatorName = opName;
	}
	else
	{
		cout << "Number or Operator name is not correct!!" << endl;
	}
}

PhoneNumber::~PhoneNumber()
{
}

void PhoneNumber::set_phone_number(string phoneNum)
{
	if (phoneNum.size() == 11)
	{
		phoneNumber = phoneNum;
	}
	else
	{
		cout << "Phone Number is not Correct!!";
	}


}

void PhoneNumber::set_operator_name(string opName)
{
	if (opName == "KomKothaKoiben" || opName == "GrameenPhone" || opName == "Robi" || opName == "Teletalk" || opName == "BanglaLink")
	{
		operatorName = opName;
	}
	else
	{
		cout << "Operator name is not Correct!!";
	}

}

string PhoneNumber::get_phone_number()
{
	return phoneNumber;
}

string PhoneNumber::get_operator_name()
{
	return operatorName;
}

/*void PhoneNumber::print_phone_number()
{
	cout << endl;
	cout << "Phone Number : \t" << phoneNumber << endl;
	cout << "Operator Name:\t" << operatorName << endl;
}*/



bool PhoneNumber::operator==(const PhoneNumber & rhs)
{
	if (this->phoneNumber == rhs.phoneNumber)
		return true;
	else
		return false;
}

bool PhoneNumber::operator<(const PhoneNumber & rhs)
{
	if (this->phoneNumber < rhs.phoneNumber)
		return true;
	else
		return false;
}

bool PhoneNumber::operator>(const PhoneNumber & rhs)
{
	if (this->phoneNumber > rhs.phoneNumber)
		return true;
	else
		return false;
}

bool PhoneNumber::enqueue_call(Call newItem)
{

	

	NodeType* newNode = new NodeType;
	newNode->info = newItem;
	NodeType* curr = front;
	NodeType* prev = nullptr;
	bool posFound = false;

	while (curr != nullptr && !posFound) {
		if (curr->info.get_relation_type() < newItem.get_relation_type()) {
			prev = curr;
			curr = curr->next;
		}
		else if (curr->info.get_relation_type() == newItem.get_relation_type())
		{
			if (curr->info.get_call_duration() <= newItem.get_call_duration())
			{
				posFound = true;
				newNode->next = curr;
				if (prev == nullptr) {
					front = newNode;
				}
				else {
					prev->next = newNode;
				}
			}
			else
			{
				posFound = true;
				prev = curr;
				curr = curr->next;
				newNode->next = curr;
				if (prev == nullptr) {
					front = newNode;
				}
				else {
					prev->next = newNode;
				}

			}
		}
		else {
			posFound = true;
			newNode->next = curr;
			if (prev == nullptr) {
				front = newNode;
			}
			else {
				prev->next = newNode;
			}
		}
	}
	if (!posFound)
	{
		posFound = true;
		newNode->next = curr;
		if (prev == nullptr) {
			front = newNode;
		}
		else {
			prev->next = newNode;

		}
		rear = newNode;
	}
	length++;
	return posFound;
	



}

bool PhoneNumber::dequeue_call(Call& call)
{
	if (call_list_is_empty()) {
		return false;
	}

	else {
		NodeType* dequeuedNode = front;
		call = dequeuedNode->info;
		front = front->next;

		if (front == nullptr)
			rear = nullptr;

		delete dequeuedNode;
		length--;
		return true;
	}

}

bool PhoneNumber::call_list_is_empty()
{
	return (front==nullptr && rear==nullptr && length==0);
}

bool PhoneNumber::call_list_isfull()
{
	try
	{
		NodeType* newNode = new NodeType();
		delete newNode;
	}
	catch (bad_alloc)
	{
		return true;
	}
	return false;
}

Call PhoneNumber::get_call()
{
	return front->info;
}

void PhoneNumber::print_call_list()
{
	NodeType* temp = front;
	while (temp != nullptr)
	{
		temp->info.print_call();
		temp = temp->next;
	}
}



ostream & operator<<(ostream & os, const PhoneNumber & phoneNumber)
{
	os << endl;
	os << "Phone Number : \t" << phoneNumber.phoneNumber << endl;
	os << "Operator Name:\t" << phoneNumber.operatorName << endl;

	return os;
}

