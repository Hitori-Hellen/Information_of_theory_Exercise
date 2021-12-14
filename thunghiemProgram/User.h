#include "QLK.h"
#include <iostream>
#pragma once

using namespace std;

class User {
protected:
    string Account;
    string Password;
    int Age;
    long Balance;
    int User_library_len;
    string *User_library;

public:
    User();
    User(string, string);
    User(string, string, int, long);
    ~User();
    void sUser_library(string*);
    void sUser_library_len(int);
    void sAccount(string);
    string gAccount();
    void sPassword(string);
    string gPassword();
    void sAge(int);
    int gAge();
    void sBalance(long);
    long gBalance();
    void Buy(string);
    void Search(string, QLK &);
    void Show_User(QLK &);
    void Show_User_Name();
};

class ListUser {
private:
    User *List_User;
    int List_user_len;

public:
    ListUser(string);
    bool Check_account(string);
    bool Check_password(string);
    bool Sign_in(string, string);
    void Sign_up(string, string);
    void Show_ListUser();
    User Return_User(string);
    int Search_user(string);
};