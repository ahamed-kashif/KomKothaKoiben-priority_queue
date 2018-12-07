#pragma once
#include "Person.h"
#include"Call.h"
#include"PhoneNumber.h"
#include<iostream>
#include <list> 
#include <iterator>

using namespace std;


class Customer :
	public Person
{

private:

	int length;
	int customerIndex;
	int phoneNumberIterator = -1;


	list<PhoneNumber> phoneNumberList;
	list<PhoneNumber>::iterator it;

public:


	Customer();//constructor
	~Customer();//destructor

	bool insert_phone_number(PhoneNumber);//inserting phone number
	bool delete_phone_number(PhoneNumber);//deleting phone number
	PhoneNumber get_phone_number(PhoneNumber);//retriving a phone number
	void get_next_phone_number(PhoneNumber&);//retriving next available phone number
	void reset_phone_number_list();//reseting the phone number iterator

	void make_empty();//deletes all phone numbers
	bool is_full();//checks if phone number list has more than 15 numbers
	bool is_empty();//makes epmty the phone number list
	void print_customer_details();//prints customer details

	void set_customer_index(int);//modifier of customer index
	int get_customer_index();//accessor of customer index
	int phone_number_get_length();//accessor for phone number list length

	bool enqueue_phone_call(PhoneNumber calledIn, Call call);//inserting call in a customer's saved phone numbers
	bool dequeue_phone_call(PhoneNumber called);//deques a call from customer's phone number
	void print_call_list();//printing all calls of a customer


	bool operator==(const Customer & rhs);//overloading operator == to compare Customer Type object
	bool operator<(const Customer & rhs);//overloading operator < to compare Customer Type object
	bool operator>(const Customer & rhs);//overloading operator > to compare Customer Type object


};

