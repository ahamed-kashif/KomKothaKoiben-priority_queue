#pragma once
#include<iostream>
#include<string>
#include"Call.h"
#include "HeapType.h"


using namespace std;



class PhoneNumber : public HeapType
{

private:

	string phoneNumber;
	string operatorName;

	


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

	
	void reheap_up(int root, int bottom) override;
	void reheap_down(int root, int bottom) override;
	
	void insert_call(Call newCall);//inserting Phone Calls
	bool call_list_is_empty();//returns if a number has phone calls or not
	Call get_call();//this function will return top most call
	void dequeue_call();//this will dequeue top most Call
	void print_call_list();//prints call list

};

