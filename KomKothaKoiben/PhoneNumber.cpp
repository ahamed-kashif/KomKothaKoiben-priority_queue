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







void PhoneNumber::enqueue_call(Call newCall)
{
	callList.push(newCall);
}

bool PhoneNumber::call_list_is_empty()
{
	return callList.empty();
}

Call PhoneNumber::get_calls()
{
	return callList.top();
}

bool PhoneNumber::dequeue_call()
{
	callList.pop();
	return true;
}

void PhoneNumber::print_call_list()
{
	if (callList.empty())
	{
		cout << "No calls have been made yet!!";
	}
	else
	{
		Calling dummy;
		dummy = callList;
		while (!dummy.empty())
		{
			Call dummyCall = dummy.top();
			dummyCall.print_call();
			dummy.pop();
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

