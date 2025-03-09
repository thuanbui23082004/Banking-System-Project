#include <iostream>
#include <string>
#include <stdlib.h>


using namespace std;

#ifndef HUMAN_H
#define HUMAN_H

class Human
{
private:
	string name;
	int age;
	string address;
	string phone;
	string dateOfBirth;
	string email;
	string id;
	string sex;

public:
	Human();
	Human(string name, string id, string sex, string address, string phone, string dateOfBirth, string email);
	~Human();
	//virtual void show();
	string getId();
	void setId(string);
	void setSex(string);
	string getName();
	void setName(string);
	string getDateOfBirth();
	void setDateOfBirth(string);
	string getAddress();
	void setAddress(string);
	int getAge();
	void setAge(int);
	string getSex();
	string getPhoneNumber();
	string getEmail();
	string standardizeName(string);
	int string_to_int(string);
	int setAgeByDateOfBirth(string);
};


#endif 
#pragma once
