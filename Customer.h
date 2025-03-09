#pragma once
#include "Human.cpp"
#include "string.h"
#include <iostream>
#include <fstream>



using namespace std;

#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer :public Human {
private:
	std::string username;
	string password;
	int balance;
	string accountNumber;

public:

	Customer();
	Customer(string n, string id, string sex, string ad, string te, string d, string mail, std::string username, string password, int balance = 0, int accountNumber);
	~Customer();
	std::string getUsername();
	void setUsername(std::string);
	string getPassword();
	void setPassword(string);
	int getBalance();
	void setBalance(int);
	string getAccountNumber();
	void setAccountNumber(string);

	//t?o tài kho?n m?i
	void createAccount();


	//xu li voi file 
	void saveCustomeToFile(ofstream&, int = 0);

	//register


	//doi mk
	void changePassword();

	//logn in
	bool checkLogin(string username, string password);


	//show
	void enterInforCustomer();
	Customer getCustomerById(int id);

	//xóa
	void deleteCustomer();

	//rut tien

	//nap tien

	//



};




#endif
