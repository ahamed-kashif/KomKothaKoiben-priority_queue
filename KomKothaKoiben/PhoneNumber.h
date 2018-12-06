#pragma once
#include<iostream>
#include<string>
#include <queue>
#include"Call.h"

using namespace std;

struct comparision //this struct is used to compare Call class obeject in STL priority_queue
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

	Calling callList;


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

	void insert_call(Call newCall);//inserting Phone Calls
	bool call_list_is_empty();//returns if a number has phone calls or not
	Call get_calls();//this function will return top most call
	bool dequeue_call();//this will dequeue top most Call
	void print_call_list();//prints call list

};

