#pragma once
#include<exception>
#include <list> 
#include <iterator>
#include<string>
#include"Customer.h"

using namespace std;

class KomKothaKoibenSTLPriorityQueue
{
private:
	std::list<Customer> customerList;
	std::list<Customer>::iterator it;





public:
	KomKothaKoibenSTLPriorityQueue();
	~KomKothaKoibenSTLPriorityQueue();



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

	//bool change_operator_name(Customer, PhoneNumber, string);
};

