#include "PhoneNumber.h"

using namespace std;

PhoneNumber::PhoneNumber()
{
	phoneNumber = "";
	operatorName = "";
}


PhoneNumber::PhoneNumber(string phNumber, string opName)
{
	if (phNumber.size() == 11 && opName == "KomKothaKoiben" || opName == "GrameenPhone" || opName == "Robi" || opName == "Teletalk" || opName == "BanglaLink")
	{
		phoneNumber = phNumber;
		operatorName = opName;
	}
	else
	{
		throw WrongNumber();
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
		throw WrongNumber();


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

void PhoneNumber::reheap_up(int root, int bottom)
{
	int parent;
	if (root < bottom)
	{
		parent = bottom - 1 / 2;
		
		if (item[parent].get_relation_type()<item[bottom].get_relation_type())
		{
			swap(item[parent], item[bottom]);
			reheap_up(root, parent);
		}
		else if (item[parent].get_relation_type() == item[bottom].get_relation_type())
		{
			if (item[parent].get_call_duration() > item[bottom].get_call_duration())
			{
				swap(item[parent], item[bottom]);
				reheap_up(root, parent);
			}
		}
	}
}

void PhoneNumber::reheap_down(int root, int bottom)
{
	int minChild;
	int leftChild= 2 * root + 1;
	int rightChild= 2 * root + 2;
	if (root < bottom)
	{
		minChild = leftChild;
		if (root < rightChild)
		{
			if (item[rightChild].get_relation_type() < item[leftChild].get_relation_type())
			{
				minChild = rightChild;
			}
			else if (item[rightChild].get_relation_type() == item[leftChild].get_relation_type())
			{
				if (item[rightChild].get_call_duration() >= item[leftChild].get_call_duration())
				{
					minChild = rightChild;
				}
				else
					minChild = leftChild;
			}
			else
				minChild = leftChild;
		}
		if (item[minChild].get_relation_type() < item[root].get_relation_type())
		{
			swap(item[minChild], item[root]);
			reheap_down(minChild, bottom);
		}
		else if (item[minChild].get_relation_type() == item[root].get_relation_type())
		{
			if (item[minChild].get_call_duration() >= item[root].get_call_duration())
			{
				swap(item[minChild], item[root]);
				reheap_down(minChild, bottom);
			}
		}

	}

}



ostream & operator<<(ostream & os, const PhoneNumber & phoneNumber)
{
	os << endl;
	os << "Phone Number : \t" << phoneNumber.phoneNumber << endl;
	os << "Operator Name:\t" << phoneNumber.operatorName << endl;

	return os;
}

