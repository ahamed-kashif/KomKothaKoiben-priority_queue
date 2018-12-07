#pragma once
#include<exception>
#include <list> 
#include <iterator>
#include<string>
#include"Customer.h"

using namespace std;


class Company
{

private:
	std::list<Customer> customerList;
	std::list<Customer>::iterator it;





public:
	Company();
	~Company();



	int get_length();
	void make_empty();
	bool is_empty();

	Customer get_customer_details(Customer);
	bool put_customer_details(Customer);
	bool delete_customer_details(Customer);



	//Printing List Contents
	void print_customer_list();

	//phone number updating
	bool insert_new_number(Customer, PhoneNumber);
	bool delete_phone_number(Customer, PhoneNumber);

	

	bool insert_call_in_database(Customer, PhoneNumber, Call);//inserting calls in company's database
	bool dequeue_call_from_database(Customer, PhoneNumber);//dequeues call from a number of a customer from database
	void print_phone_call_list(Customer);//printing a specific customer's (stored in database) call list
};


