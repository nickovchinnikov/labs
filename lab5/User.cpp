#include "User.h"
#include <iostream>

using namespace std;

// User class implementation

User::User(const string& username, const string& email, int age)
    : username(username), email(email), age(age) {}

User::User()
    : User("", "", 0) {}

void User::setUsername(const string& username) {
    this->username = username;
}

string User::getUsername() const {
    return username;
}

void User::setEmail(const string& email) {
    this->email = email;
}

string User::getEmail() const {
    return email;
}

void User::setAge(int age) {
    this->age = age;
}

int User::getAge() const {
    return age;
}

void User::printInfo() const {
    cout << "Username: " << username << endl;
    cout << "Email: " << email << endl;
    cout << "Age: " << age << endl;
}

// RegisteredUser class implementation

RegisteredUser::RegisteredUser(const string& username, const string& email, int age, const string& password)
    : User(username, email, age), password(password) {}

void RegisteredUser::setPassword(const string& password) {
    this->password = password;
}

string RegisteredUser::getPassword() const {
    return password;
}

void RegisteredUser::printInfo() const {
    User::printInfo();
    cout << "Password: " << password << endl;
}

// AdminUser class implementation

AdminUser::AdminUser(const string& username, const string& email, int age, const string& role)
    : User(username, email, age), role(role) {}

void AdminUser::setRole(const string& role) {
    this->role = role;
}

string AdminUser::getRole() const {
    return role;
}

void AdminUser::printInfo() const {
    User::printInfo();
    cout << "Role: " << role << endl;
}
