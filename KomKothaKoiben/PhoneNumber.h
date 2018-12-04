#pragma once
#include<iostream>
#include<string>
#include <queue>
#include"Call.h"

using namespace std;

struct comparision
{
	bool operator()(Call called, Call calling)
	{
		if (called.get_relation_type() > calling.get_relation_type())
			return true;
		else if (called.get_relation_type() == calling.get_relation_type())
		{
			if (called.get_call_duration() < calling.get_call_duration())
				return true;
			else
				return false;
		}
		else
			return false;
	}
};

class PhoneNumber
{

private:

	string phoneNumber;
	string operatorName;
	
	typedef priority_queue<Call, std::vector<Call>, comparision> Calling;

	Calling calList;


public:
	PhoneNumber();//constructor
	PhoneNumber(string, string);//parameterized constructor
	~PhoneNumber();	//destructor


	void set_operator_name(string);//modifier
	void set_phone_number(string);//modifier



	string get_phone_number();//accessor
	string get_operator_name();//accessor

	//void print_phone_number();

	bool operator==(const PhoneNumber & rhs);//overloading operator == to compare PhoneNumber Type object
	bool operator<(const PhoneNumber & rhs);//overloading operator < to compare PhoneNumber Type object
	bool operator>(const PhoneNumber & rhs);//overloading operator > to compare PhoneNumber Type object
	friend ostream& operator<<(ostream& os, const PhoneNumber& phoneNumber);//overloading operator << to print PhoneNumber Type object

	

};

