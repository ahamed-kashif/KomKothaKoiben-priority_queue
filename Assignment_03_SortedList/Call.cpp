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

	catch (WrongNumber)
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

bool Call::operator==(const Call& rhs)
{
	if (this->relation == rhs.relation && this->time == rhs.time)
		return true;
	else
		return false;
}

bool Call::operator<(const Call & rhs)
{
	if (this->relation == rhs.relation)
	{
		if (this->time < rhs.time)
			return true;
	}
	if (this->relation < rhs.relation)
		return true;
	else
		return false;
}

bool Call::operator>(const Call & rhs)
{
	if (this->relation == rhs.relation)
	{
		if (this->time > rhs.time)
			return true;
	}
	if (this->relation > rhs.relation)
		return true;
	else
		return false;
}


void Call::print_call()
{
	switch (relation)
	{
	case spouse:
		cout << "\t\t" << "Spouse " << relation << " " << time << " sec" << endl;
		break;
	case Child:
		cout << "\t\t" << "Child " << relation << " " << time << " sec" << endl;
		break;
	case Parent:
		cout << "\t\t" << "Parents " << relation << " " << time << " sec" << endl;
		break;
	case Sibling:
		cout << "\t\t" << "Sibling " << relation << " " << time << " sec" << endl;
		break;
	case Aunt:
		cout << "\t\t" << "Aunt " << relation << " " << time << " sec" << endl;
		break;
		/*case Uncle:
			cout << "\t\t" << "Uncle" << relation << " " << time << endl;
			break;*/
	case Cousins:
		cout << "\t\t" << "Cousins " << relation << " " << time << " sec" << endl;
		break;
	case Significant:
		cout << "\t\t" << "Significant " << relation << " " << time << " sec" << endl;
		break;
	case Friend:
		cout << "\t\t" << "Friend " << relation << " " << time << " sec" << endl;
		break;
	case Subordinate:
		cout << "\t\t" << "Subordinate " << relation << " " << time << " sec" << endl;
		break;
	case Acquaintance:
		cout << "\t\t" << "Acquaintance " << relation << " " << time << " sec" << endl;
		break;
	case Boss:
		cout << "\t\t" << "Boss " << relation << " " << time << " sec" << endl;
		break;
	case Blocked:
		cout << "\t\t" << "Blocked " << relation << " " << time << " sec" << endl;
		break;
	}

}


