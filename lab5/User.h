#ifndef USER_H
#define USER_H

#include <string>

using namespace std;

class User {
private:
    string username;
    string email;
    int age;

public:
    User(const string& username, const string& email, int age);
    User();

    void setUsername(const string& username);
    string getUsername() const;

    void setEmail(const string& email);
    string getEmail() const;

    void setAge(int age);
    int getAge() const;

    void printInfo() const;
};

class RegisteredUser : public User {
private:
    string password;

public:
    RegisteredUser(const string& username, const string& email, int age, const string& password);

    void setPassword(const string& password);
    string getPassword() const;

    void printInfo() const;
};

class AdminUser : public User {
private:
    string role;

public:
    AdminUser(const string& username, const string& email, int age, const string& role);

    void setRole(const string& role);
    string getRole() const;

    void printInfo() const;
};

#endif
