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





ostream & operator<<(ostream & os, const PhoneNumber & phoneNumber)
{
	os << endl;
	os << "Phone Number : \t" << phoneNumber.phoneNumber << endl;
	os << "Operator Name:\t" << phoneNumber.operatorName << endl;

	return os;
}

