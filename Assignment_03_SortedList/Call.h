#pragma once
#include<string>
#include<iostream>
#include<exception>

using namespace std;


class WrongNumber {
public:
	std::string Error() { return "Entered Phone Number is not correct!"; }
};

enum relationship { spouse = 1, Child = 2, Parent = 3, Sibling = 4, Aunt = 5, Uncle = 5, Cousins = 6, Significant = 7, Friend = 8, Boss = 9, Subordinate = 10, Acquaintance = 11, Blocked = 12 };
class Call
{
public:

	Call();
	Call(string phone, string name, relationship relation);
	~Call();


	void set_phone_number(string phone);
	void set_caller_name(string caller);
	void set_relationship(relationship relationType);
	void set_call_duration(double seconds);

	string get_phone_number();
	string get_caller_name();
	relationship get_relation_type();
	double get_call_duration();

	

	void print_call();


private:
	string phoneNumber;
	string name;
	relationship relation;
	double time;

};

