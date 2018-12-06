#include "Company.h"



Company::Company()
{

}



Company::~Company()
{
	make_empty();
}


int Company::get_length()
{
	return customerList.size();
}


void Company::make_empty()
{
	customerList.clear();
}


bool Company::is_empty()
{
	return customerList.empty();
}


Customer Company::get_customer_details(Customer item)
{
	Customer tempItem;
	for (auto it = customerList.begin(); it != customerList.end(); it++)
	{
		tempItem = *it;
		if (tempItem == item)
		{
			return tempItem;
		}
	}
	cout << "Customer Not Found!!" << endl;
	return item;
}


bool Company::put_customer_details(Customer item)
{
	try
	{
		if (is_empty())
		{
			customerList.push_front(item);
			return true;
		}
		else
		{
			Customer tempItem;

			for (it = customerList.begin(); it != customerList.end(); it++)
			{
				tempItem = *it;
				if (tempItem > item)
				{
					customerList.insert(it, item);
					return true;
				}
			}

			customerList.push_back(item);
			return true;
		}
	}
	catch (bad_alloc&)
	{
		cout << "Run Out of Storage!!" << endl;
	}


}


bool Company::delete_customer_details(Customer item)
{
	Customer tempItem;

	for (auto it = customerList.begin(); it != customerList.end(); it++)
	{
		tempItem = *it;
		if (tempItem.get_customer_index() == item.get_customer_index())
		{
			customerList.erase(it);
			return true;
		}
	}
	cout << endl << "Customer is not Correct" << endl;
	return false;
}





void Company::print_customer_list()
{
	Customer customer;

	for (auto it = customerList.begin(); it != customerList.end(); it++)
	{
		customer = *it;
		customer.print_customer_details();
		cout << endl;
		cout << endl;
	}
}

bool Company::insert_new_number(Customer customer, PhoneNumber phone)
{
	Customer temCustomer;
	for (auto it = customerList.begin(); it != customerList.end(); it++)
	{
		temCustomer = *it;
		if (temCustomer == customer)
		{
			customer.insert_phone_number(phone);
			*it = customer;
			cout << endl << "A New Phone number is been ADDED to " << customer.get_name() << "'s deatils !!" << endl << endl;
			return true;
		}
	}
	cout << endl << "Customer Index or is not CORRECT!!" << endl << endl;
	return false;
}

bool Company::delete_phone_number(Customer customer, PhoneNumber phoneNumber)
{
	Customer customer1;
	for (it = customerList.begin(); it != customerList.end(); it++)
	{
		customer1 = *it;
		if (customer1 == customer)
		{
			customer1.delete_phone_number(phoneNumber);
			*it = customer1;
			cout << endl << "A Number is been deleted from " << customer.get_name() << "'s deatils !!" << endl << endl;

			if (customer1.phone_number_get_length() == 0)
			{
				delete_customer_details(customer1);
				cout << endl << customer.get_name() << "'s deatils is deleted !!" << endl << endl;
			}

			return true;
		}
	}
	cout << endl << "Customer Index or Phone Number Index is not CORRECT!!" << endl << endl;
	return false;
}

bool Company::insert_call_in_database(Customer customer, PhoneNumber phoneNumber, Call inComingCall)
{
	Customer customerFromList;
	for (it = customerList.begin(); it != customerList.end(); it++)
	{
		customerFromList = *it;

		if (customerFromList == customer && customerFromList.get_phone_number(phoneNumber) == phoneNumber)
		{
			customerFromList.insert_phone_call(phoneNumber, inComingCall);
			*it = customerFromList;
			return true;
		}
	}
	cout << "This Customer is not in Database!!" << endl;
	return false;
}

void Company::print_phone_call_list(Customer customer)
{
	Customer customerFromList;
	for (it = customerList.begin(); it != customerList.end(); it++)
	{
		customerFromList = *it;
		if (customerFromList == customer)
		{
			cout << endl;
			cout << endl;
			cout << "Customer ID: #" << customerFromList.get_customer_index() << endl;
			cout << "\t" << customerFromList.get_name() << endl;
			cout << endl;
			customerFromList.print_call_list();
			return;
		}
	}
}

