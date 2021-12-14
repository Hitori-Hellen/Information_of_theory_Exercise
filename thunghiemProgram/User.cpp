#include "User.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

User::User() {
}
User::User(string User_Account, string User_Password) {
    this->Account = User_Account;
    this->Password = User_Password;
    this->Age = 0;
    this->Balance = 0;
    this->User_library = nullptr;
    this->User_library_len = 0;
}
User::User(string User_Account, string User_Password, int User_Age, long User_Balance) {
    this->Account = User_Account;
    this->Password = User_Password;
    this->Age = User_Age;
    this->Balance = User_Balance;
    this->User_library = nullptr;
    this->User_library_len = 0;
}
User::~User() {
}
void User::sUser_library(string arr[]){
    for(int i = 0; i < this->User_library_len; i++){
        *(this->User_library + i) = arr[i];
    }
}
void User::sUser_library_len(int len) {
    this->User_library_len = len;
}
void User::sAccount(string User_Account) {
    this->Account = User_Account;
}
string User::gAccount() {
    return this->Account;
}
void User::sPassword(string User_Password) {
    this->Password = User_Password;
}
string User::gPassword() {
    return this->Password;
}
void User::sAge(int User_Age) {
    this->Age = User_Age;
}
int User::gAge() {
    return this->Age;
}
void User::sBalance(long User_Balance) {
    this->Balance = User_Balance;
}
long User::gBalance() {
    return this->Balance;
}
void User::Buy(string Game_ID) {
    string *Temp = new string[this->User_library_len];
    for (int i = 0; i < this->User_library_len; i++) {
        *(Temp + i) = *(this->User_library + i);
    }
    delete[] this->User_library;
    this->User_library = new string[this->User_library_len + 1];
    for (int i = 0; i < this->User_library_len; i++) {
        *(this->User_library + i) = *(Temp + i);
    }
    *(this->User_library + this->User_library_len) = Game_ID;
    this->User_library_len++;
}
bool Find_Char(string Str, string inp) {
    bool checkushimasu = false;
    for (int i = 0; i < Str.length(); i++) {
        if (inp[0] == Str[i]) {
            checkushimasu = true;
            break;
        }
    }
    if (checkushimasu == true) {
        return true;
    } else {
        return false;
    }
}
// void User::Search(string Game_ID, QLK& DB){
//     int Game_index = DB.Search(Game_ID);
//     for(int i = 0; i < DB.Length(); i++){
//         if(Find_Char((*(DB->arr + Game_index)), Game_ID) == true){

//         }
//     }
// }
void User::Show_User(QLK &DB) {
    cout << this->Age << " " << this->Balance << endl;
    for (int i = 0; i < this->User_library_len; i++) {
        int Game_index = DB.Search(*(this->User_library + i));
        Game obj_temp = DB.Return_object(Game_index);
        obj_temp.Show();
    }
}
void User::Show_User_Name() {
    cout << this->Account << " " << this->Password << endl;
}

ListUser::ListUser(string FilePath_user) {
    int number_of_lines = 0;
    ifstream in;
    in.open(FilePath_user);
    string line;
    while (getline(in, line)) {
        ++number_of_lines;
    }
    this->List_user_len = 0;
    this->List_User = new User[number_of_lines];
    in.close();
    string Var_User_Account;
    string Var_User_Password;
    int Var_User_Age;
    long Var_User_Balance;
    int Var_User_library_len;
    string Var_User_Game_Id;
    in.open(FilePath_user);
    string line1;
    while (getline(in, line1)) {
        istringstream iss(line1);
        iss >> Var_User_Account >> Var_User_Password >> Var_User_Age >> Var_User_Balance >> Var_User_library_len;
        string *arr = new string[Var_User_library_len];
        int i = 0;
        while (iss >> Var_User_Game_Id) {
            *(arr + i) = Var_User_Game_Id;
            i++;
        }
        User User_Temp_obj;
        User_Temp_obj.sAccount(Var_User_Account);
        User_Temp_obj.sPassword(Var_User_Password);
        User_Temp_obj.sAge(Var_User_Age);
        User_Temp_obj.sBalance(Var_User_Balance);
        User_Temp_obj.sUser_library_len(Var_User_library_len);
        User_Temp_obj.sUser_library(arr);
        *(this->List_User + this->List_user_len) = User_Temp_obj;
        this->List_user_len++;
    }
    in.close();
}
bool ListUser::Sign_in(string Input_Account, string Input_Password) {
    bool inp = false;
    for (int i = 0; i < this->List_user_len; i++) {
        if ((this->List_User + i)->gAccount() == Input_Account && (this->List_User + i)->gPassword() == Input_Password) {
            inp = true;
            break;
        }
    }
    if (inp == true) {
        return inp;
    } else {
        return false;
    }
}
bool ListUser::Check_account(string Input) {
    bool inp = false;
    for (int i = 0; i < this->List_user_len; i++) {
        if ((this->List_User + i)->gAccount() == Input) {
            inp = true;
        }
    }
    if (inp == true) {
        return inp;
    } else {
        return false;
    }
}
bool ListUser::Check_password(string Input) {
    bool inp = false;
    for (int i = 0; i < this->List_user_len; i++) {
        if ((this->List_User + i)->gPassword() == Input) {
            inp = true;
        }
    }
    if (inp == true) {
        return inp;
    } else {
        return false;
    }
}
void ListUser::Sign_up(string Input_Account, string Input_Password) {
    if (this->Check_account(Input_Account) == false) {
        if (this->Check_password(Input_Password) == false) {
            User Person(Input_Account, Input_Password);
            cout << "Please enter your age: ";
            int Input_Age;
            cin >> Input_Age;
            Person.sAge(Input_Age);
            User *Temp = new User[this->List_user_len];
            for (int i = 0; i < this->List_user_len; i++) {
                *(Temp + i) = *(this->List_User + i);
            }
            delete[] this->List_User;
            this->List_User = new User[this->List_user_len + 1];
            for (int i = 0; i < this->List_user_len; i++) {
                *(this->List_User + i) = *(Temp + i);
            }
            *(this->List_User + this->List_user_len) = Person;
            this->List_user_len++;
        } else {
            cout << "Your Password is used. Please use another one!!!" << endl;
        }
    } else {
        cout << "Your account is used. Please use another name!!!" << endl;
    }
}
void ListUser::Show_ListUser() {
    cout << this->List_user_len << endl;
    for (int i = 0; i < this->List_user_len; i++) {
        (*(this->List_User + i)).Show_User_Name();
    }
}
int ListUser::Search_user(string User_name) {
    int base = -1;
    for (int i = 0; i < this->List_user_len; i++) {
        if ((this->List_User + i)->gAccount() == User_name) {
            base = i;
            break;
        }
    }
    return base;
}
User ListUser::Return_User(string User_Name) {
    int Index_User = Search_user(User_Name);
    User Temp_User;
    Temp_User = *(this->List_User + Index_User);
    return Temp_User;
}