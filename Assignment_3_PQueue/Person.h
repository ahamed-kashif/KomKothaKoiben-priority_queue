#pragma once
#include<string>
#include<iostream>

using namespace std;

class Person
{
protected:
	string name;
	string fatherName;
	string motherName;
	int age;
	char gender;
	bool maritalStatus;
	char* NID;
	string presentAddress;
	string permanentAddress;
	float height;
	float weight;
	string eyeColor;
	string hairColor;

public:

	Person();                                   //constructor
	~Person();                                 //destructor
	Person(string, string, char[11]);           //parameterized_constructor

	void set_name(string);                      //modifier
	void set_father_name(string);              //modifier
	void set_mother_name(string);             //modifier
	void set_age(int);     			         //modifier
	void set_gender(char);                  //modifier
	void set_marital_status(bool);           //modifier
	void set_national_ID(char[11]);         //modifier
	void set_present_address(string);      //modifier
	void set_permanent_address(string);   //modifier
	void set_height(float);              //modifier
	void set_weight(float);             //modifier
	void set_eye_color(string);        //modifier
	void set_hair_color(string);      //modifier


	string get_name();                 //accessor
	string get_father_name();         //accessor
	string get_mother_name();        //accessor
	int get_age();					//accessor
	char get_gender();             //accessor
	bool get_marital_status();      //accessor
	char* get_national_ID();       //accessor
	string get_present_address(); //accessor
	string get_permanent_address();  //accessor
	float get_height();             //accessor
	float get_weight();            //accessor
	string get_eye_color();       //accessor
	string get_hair_color();     //accessor


	void print_person();       //printing function

	friend ostream& operator<<(ostream& os, const Person& person);//overloaded << operator for printing person
};

