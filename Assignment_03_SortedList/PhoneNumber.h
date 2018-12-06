#pragma once
#include<iostream>
#include<string>
#include <queue>
#include"Call.h"

using namespace std;


class PhoneNumber
{
	struct NodeType
	{
		Call info;
		NodeType* next;
	};

private:
	string phoneNumber;
	string operatorName;
	
	NodeType* front;
	NodeType* rear;
	int length = 0;


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

	bool insert_call(Call newCall);//inserting calls
	bool dequeue_call();//dequeues a call
	bool call_list_is_empty();//checking if call list is empty
	bool call_list_isfull();//checks if call lis full
	Call get_call();//returns the top most call
	void print_call_list();//prints call history



};

