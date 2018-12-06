#include <iostream>
#include"Call.h"
#include"PhoneNumber.h"
#include"Customer.h"
using namespace std;

int main()
{
	PhoneNumber numOne, numTwo, numThree, numFour, numFive, numSix, numSeven, numEight, numNine, numTen, numEleven, numTwelve, numTherteen, numFourteen, numFifteen;

	numOne.set_phone_number("01783511730");
	numOne.set_operator_name("GrameenPhone");

	numTwo.set_phone_number("01715583543");
	numTwo.set_operator_name("GrameenPhone");

	Call call("01738539000", "Z", spouse);
	call.set_call_duration(44.44);

	Call call1("01738533900", "Y", spouse);
	call1.set_call_duration(200.02);

	Call call2("01738539002", "Z", Parent);
	call2.set_call_duration(55.59);

	

	//numOne.get_calls();
	
	Customer customer;
	customer.set_name("Oyon");
	customer.set_father_name("Anudip");
	customer.set_mother_name("Promila");
	string nid = "19992222341";
	char customerNID[11];
	for (int index = 0; index < 11; index++)
	{
		customerNID[index] = nid[index];
	}
	customer.set_age(19);
	customer.set_gender('M');
	customer.set_national_ID(customerNID);
	customer.set_present_address("Dhaka");
	customer.set_permanent_address("Mymensingh");
	customer.set_marital_status(false);
	customer.set_customer_index(1);
	customer.set_eye_color("Brown");
	customer.set_hair_color("Black");
	customer.set_height(5.5);
	customer.set_weight(42);
	customer.insert_phone_number(numOne);
	customer.insert_phone_number(numTwo);

	customer.insert_phone_call(numOne, call);
	customer.insert_phone_call(numOne, call1);
	customer.insert_phone_call(numOne, call2);
	customer.print_call_list();
}


