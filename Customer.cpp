#include "Customer.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <Windows.h>
#include <cstring>
#include "string.h"

using namespace std;

Customer::Customer()
{
	this->username = "";
	this->password = "";
	this->balance = 0;
	this->accountNumber = "";
}


Customer::Customer(string name, string id, string sex, string address, string phone, string date,
	string mail, std::string username, string password, int balance, int accountNumber)
	: Human(name, id, sex, address, phone, date, mail)
{
	this->username = username;
	this->password = password;
	this->balance = balance;
	this->accountNumber = accountNumber;
}
std::string Customer::getUsername()
{
	return this->username;
}
void Customer::setUsername(std::string username)
{
	// Kiểm tra độ dài
	if (username.length() < 5 || username.length() > 20) {
		cout << "Username phải từ 5 đến 20 ký tự!" << endl;
		return;
	}

	// Kiểm tra có chứa ký tự không hợp lệ không (chỉ chấp nhận chữ và số)
	for (char c : username) {
		if (!isalnum(c)) { // Nếu không phải chữ hoặc số
			cout << "Username chỉ được chứa chữ cái và số!" << endl;
			return;
		}
	}

	// Kiểm tra username có khoảng trắng không
	if (username.find(' ') != -1) {
		cout << "Username không được chứa khoảng trắng!" << endl;
		return;
	}

	// Nếu hợp lệ, gán vào thuộc tính username
	this->username = username;
}

string Customer::getPassword()
{
	return this->password;
}

void Customer::setPassword(string password)
{
	// Kiểm tra độ dài
	if (password.length() < 5 || password.length() > 20) {
		cout << "Password phải từ 5 đến 20 ký tự!" << endl;
		return;
	}

	// Nếu hợp lệ, gán vào thuộc tính password
	this->password = password;
}

int Customer::getBalance()
{
	return this->balance;
}

void Customer::setBalance(int balance)
{
	this->balance = balance;
}

string Customer::getAccountNumber()
{
	return this->accountNumber;
}


//void Customer::createAccount()
//{
//	string username;
//	getline(cin, username);
//	setUsername(username);
//	cout << "Nhap mat khau: ";
//	string password;
//	getline(cin, password);
//	setPassword(password);
//	cout << "Nhap so du: ";
//	int balance;
//	cin >> balance;
//	setBalance(balance);
//	cout << "Nhap so tai khoan: ";
//	string accountNumber;
//	getline(cin, accountNumber);
//	setAccountNumber(accountNumber);
//}

void Customer::saveCustomeToFile(ofstream& o, int check)
{
	ifstream f("CustomerInfo.txt");
	bool isEmpty = false;

	if (!f.is_open()) {
		isEmpty = true; // Nếu file chưa tồn tại, cần ghi tiêu đề
	}
	else {
		f.seekg(0, ios::end);
		isEmpty = (f.tellg() == 0);
		f.close();
	}
	if (check == 0 && isEmpty) {
		o << left << setw(10) << "ID" << setw(25) << "Name" << setw(5) << "Sex" << setw(17) << "dateOfBirth"
			<< setw(15) << "address" << setw(15) << "age" << setw(15) << ""
			<< setw(15) << "PhoneNumber" << setw(30) << "email";
	}
	if (check == 1) {
		o << left << setw(10) << "ID" << setw(25) << "Name" << setw(5) << "Sex" << setw(17) << "dateOfBirth"
			<< setw(15) << "address" << setw(15) << "age" << setw(15) << ""
			<< setw(15) << "PhoneNumber" << setw(30) << "email";
	}
	if (o.is_open()) {
		o << left << setw(10) << this->getId() << "," << setw(25) << getName() << "," << setw(5) << this->getSex() << ","
			<< setw(17) << getDateOfBirth() << "," << setw(15) << this->getAddress() << ","
			<< setw(15) << this->getAge() << "," << setw(15) << this->getPhoneNumber() << ","
			<< setw(15) << this->getPhoneNumber() << "," << setw(15) << this->getEmail() << endl;
	}
}

//Customer Customer::getCustomerById(int id) {
//    ifstream i("Player.txt");
//    if (!i.is_open()) // Thêm kiểm tra !  
//    {
//        cout << "Khong the mo file Player.txt!\n";
//        return Player(); // Trả về một đối tượng Player mặc định nếu không mở được file  
//    }
//
//    string tmp;
//    string::getline(i, tmp); // Đọc dòng tiêu đề và bỏ qua nó  
//
//    while (string::getline(i, tmp)) // Sử dụng getline làm điều kiện vòng lặp  
//    {
//        // Loại bỏ khoảng trắng ở đầu và cuối dòng  
//        tmp.trim(); // Giả sử string có hàm trim()  
//        if (tmp.empty() || tmp[0] == '\n') // Kiểm tra dòng trống sau khi trim  
//        {
//            continue;
//        }
//        int check = 1;
//        bool status = false;
//        string id, name, date, address, age, numberClo, yellowCard, redCard, goal, nameTeam;
//        id = name = date = address = age = numberClo = yellowCard = redCard = goal = nameTeam = ""; // Khởi tạo các chuỗi  
//
//        for (int k = 0; k < tmp.size(); k++) // Sửa thành k để tránh trùng lặp biến i  
//        {
//            if (tmp[k] == ',')
//            {
//                status = false;
//                check++;
//                continue;
//            }
//            status = true; // Đặt status = true khi bắt đầu đọc một trường  
//            if (check == 1 && status)
//                id = id + tmp[k];
//            else if (check == 2 && status)
//                name = name + tmp[k];
//            else if (check == 3 && status)
//                date = date + tmp[k];
//            else if (check == 4 && status)
//                address = address + tmp[k];
//            else if (check == 5 && status)
//                age = age + tmp[k];
//            else if (check == 6 && status)
//                numberClo = numberClo + tmp[k];
//            else if (check == 7 && status)
//                yellowCard = yellowCard + tmp[k];
//            else if (check == 8 && status)
//                redCard = redCard + tmp[k];
//            else if (check == 9 && status)
//                goal = goal + tmp[k];
//            else if (check == 10 && status && tmp[k] != '\n')
//                nameTeam = nameTeam + tmp[k];
//        }
//
//        if (id == idF)
//        {
//            Player p(id, name, date, address, nameTeam, string::toint(numberClo), string::toint(goal), string::toint(yellowCard), string::toint(redCard));
//            i.close(); // Đóng file trước khi trả về  
//            return p;
//        }
//    }
//    i.close(); // Đóng file nếu không tìm thấy cầu thủ  
//    return Player(); // Trả về một đối tượng Player mặc định nếu không tìm thấy  
//}
//
//
//








Customer::~Customer()
{
}

