#include"Customer.h"


Customer::Customer()
{

}


Customer::~Customer()
{
	make_empty();
}


bool Customer::insert_phone_number(PhoneNumber item)
{
	if (!is_full())
	{
		if (!phoneNumberList.empty())
		{
			PhoneNumber tempItem;
			for (it = phoneNumberList.begin(); it != phoneNumberList.end(); it++)
			{
				tempItem = *it;
				if (tempItem > item || tempItem == item)
				{
					phoneNumberList.insert(it, item);
					length++;
					return true;
				}

			}
			phoneNumberList.push_back(item);
			return true;
		}
		else
			phoneNumberList.push_front(item);
		return true;
	}
	else
		return false;
}


bool Customer::delete_phone_number(PhoneNumber phoneNumber)
{
	PhoneNumber temPhoneNumber;
	for (it = phoneNumberList.begin(); it != phoneNumberList.end(); it++)
	{
		temPhoneNumber = *it;
		if (temPhoneNumber == phoneNumber)
		{
			phoneNumberList.erase(it);

			return true;
		}
	}
	cout << "Phone number is not correct!!" << endl;
	return false;
}


PhoneNumber Customer::get_phone_number(PhoneNumber item)
{
	PhoneNumber tempItem;
	for (auto it = phoneNumberList.begin(); it != phoneNumberList.end(); it++)
	{
		tempItem = *it;
		if (tempItem == item)
		{
			return tempItem;
		}
	}
	cout << "Phone Number is not Correct!!" << endl;
	return phoneNumberList.front();
}

void Customer::get_next_phone_number(PhoneNumber& phone)
{
	if (is_empty())
		return;

	auto iterator = next(phoneNumberList.begin(), phoneNumberList.size());
	phone = *iterator;
	phoneNumberIterator++;

}

void Customer::reset_phone_number_list()
{
	phoneNumberIterator = -1;
}



void Customer::make_empty()
{
	phoneNumberList.clear();
}


bool Customer::is_full()
{
	return (phoneNumberList.size() == 15);
}


bool Customer::is_empty()
{
	return (phoneNumberList.empty());
}


void Customer::print_customer_details()
{
	PhoneNumber temp;
	print_person();

	for (it = phoneNumberList.begin(); it != phoneNumberList.end(); it++)
	{
		temp = *it;
		cout << temp;
	}
}


void Customer::set_customer_index(int index)
{
	customerIndex = index;
}


int Customer::get_customer_index()
{
	return customerIndex;
}


int Customer::phone_number_get_length()
{
	return phoneNumberList.size();
}

/*bool Customer::insert_phone_call(PhoneNumber calledIn, Call call)
{
	PhoneNumber phoneNumber;
	for (it = phoneNumberList.begin(); it != phoneNumberList.end(); it++)
	{
		phoneNumber = *it;

		if (phoneNumber == calledIn)
		{
			phoneNumber.insert_call(call);
			*it = phoneNumber;
			return true;
		}
		else
		{
			continue;
		}
	}

	cout << "Phone Number is not currect" << endl;
	return false;
}

void Customer::print_call_list()
{
	PhoneNumber number;

	for (it = phoneNumberList.begin(); it != phoneNumberList.end(); it++)
	{
		number = *it;
		if (!number.call_list_is_empty())
		{

			cout << "\t" << number.get_operator_name() << "  " << number.get_phone_number() << endl;
			cout << "\tCalls: " << endl;
			number.print_call_list();
			cout << endl;
		}

	}
}
*/



bool Customer::operator==(const Customer& rhs)
{
	if (this->NID == rhs.NID)
		return true;
	else
		return false;
}


bool Customer::operator<(const Customer& rhs)
{
	if (this->NID < rhs.NID)
		return true;
	else
		return false;
}


bool Customer::operator>(const Customer& rhs)
{
	if (this->NID > rhs.NID)
		return true;
	else
		return false;
}

