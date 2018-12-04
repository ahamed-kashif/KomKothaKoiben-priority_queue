#include "Call.h"



Call::Call()
{
}

Call::Call(string phone, string caller, relationship relationType)
{
	try
	{
		if (phone.size() == 11)
		{
			phoneNumber = phone;
			name = caller;
			relation = relationType;
		}
	}
	
	catch(WrongNumber)
	{
		throw WrongNumber();
	}

	
}


Call::~Call()
{
}

void Call::set_phone_number(string phone)
{
	if (phone.size() == 11)
	{
		phoneNumber = phone;
	}
	else
		throw WrongNumber();
	
}

void Call::set_caller_name(string caller)
{
	name = caller;
}

void Call::set_relationship(relationship relationType)
{
	relation = relationType;
}

void Call::set_call_duration(double seconds)
{
	time = seconds;
}

string Call::get_phone_number()
{
	return phoneNumber;
}

string Call::get_caller_name()
{
	return name;
}

relationship Call::get_relation_type()
{
	return relation;
}

double Call::get_call_duration()
{
	return time;
}

void Call::print_call()
{
	cout << "Caller Name:\t" << name << endl;
	cout << "Caller Number:\t" << phoneNumber << endl;
	cout << "Call Duration:\t" << time << endl;
	cout << "Relationship:\t" << relation << endl;
}


