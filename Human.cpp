#include "Human.h"
#include "string.h"
#include <stdio.h>
#include <iostream>
#include <regex>
#include <string>
#include <cstdio> 
using namespace std;


string Human::standardizeName(string name)
{
    string tmp = "";
    bool spaceFlag = false;
    int start = 0;
    while (name[start] == ' ' && start < name.size()) {
        start++;
    }
    int end = name.size() - 1;
    while (end >= 0 && name[end] == ' ') end--;
    for (int i = start; i <= end; i++)
    {
        if (name[i] == ' ')
        {
            if (!spaceFlag) // Nếu là khoảng trắng đầu tiên
            {
                tmp = tmp + ' ';
                spaceFlag = true;
            }
        }
        else
        {
            if (tmp.empty() || tmp[tmp.size() - 1] == ' ')
                tmp += toupper(name[i]); // Viết hoa chữ cái đầu từ
            else
                tmp += tolower(name[i]); // Các ký tự còn lại viết thường

            spaceFlag = false;
        }
    }
    return tmp;
}

Human::Human(string n, string id, string sex, string ad, string te, string d, string mail)
    : Human(n, id, sex, ad, te, d, mail)
{
    this->name = this->standardizeName(n);
    this->age = this->setAgeByDateOfBirth(d);
}

Human::~Human()
{
}



string Human::getId()
{
    return this->id;
}

void Human::setId(string id)
{
    this->id = id;
}

string Human::getName()
{
    return this->name;
}

void Human::setName(string name)
{
    this->name = this->standardizeName(name);
}

string Human::getDateOfBirth()
{
    return this->dateOfBirth;
}

void Human::setDateOfBirth(string dateOfBirth)
{
    int d, m, y;
    // Kiểm tra định dạng ngày (dd/mm/yyyy) bằng regex
    if (!regex_match(dateOfBirth.c_str(), regex(R"(^\d{2}/\d{2}/\d{4}$)")) ||
        sscanf(dateOfBirth.c_str(), "%d/%d/%d", &d, &m, &y) != 3 ||
        y < 1900 || y > 2100 || m < 1 || m > 12)
    {
        cout << "Lỗi: Ngày sinh không hợp lệ!\n";
        return;
    }
    int daysInMonth[] = { 31, 28 + ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)),
                         31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    this->dateOfBirth = dateOfBirth;
    // Kiểm tra số ngày hợp lệ trong tháng


    if (d < 1 || d > daysInMonth[m - 1]) {
        cout << "Lỗi: Ngày sinh không hợp lệ!\n";
        return;
    }
    // Cập nhật ngày sinh và tính tuổi
    this->dateOfBirth = dateOfBirth;
}


string Human::getAddress()
{
    return this->address;
}

void Human::setAddress(string address)
{
    this->address = address;
}

int Human::getAge()
{
    return setAgeByDateOfBirth(this->dateOfBirth);
}


int Human::setAgeByDateOfBirth(string date) {
    int d, m, y;

    // Validate input format
    if (sscanf(date.c_str(), "%d/%d/%d", &d, &m, &y) != 3) {
        std::cerr << "Invalid date format. Use dd/mm/yyyy.\n";
        return -1;
    }

    // Validate date values
    if (m < 1 || m > 12 || d < 1 || d > 31 || y > 2100 || y < 1900) {
        std::cerr << "Invalid date values.\n";
        return -1;
    }

    // Get the current date
    time_t t = time(0);
    tm* now = localtime(&t);
    int year = now->tm_year + 1900;
    int month = now->tm_mon + 1;
    int day = now->tm_mday;

    // Calculate age
    if (month > m || (month == m && day >= d)) {
        this->age = year - y;
    }
    else {
        this->age = year - y - 1;
    }

    return this->age;
}

string Human::getSex() {
    return this->sex;
}

string Human::getPhoneNumber() {
    return this->phone;
}
string Human::getEmail() {
    return this->email;
}
Human::~Human()
{
}


