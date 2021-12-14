#include "Admin.h"
#include "QLK.h"
#include "User.h"
#include <fstream>
#include <iostream>

using namespace std;

int main() {
    string FilePath = "khogame.txt";
    string FilePath_user = "User_is.txt";
    QLK db_Game(FilePath);
    // db_Game.Show();
    ListUser db_User(FilePath_user);
    Admin Admin;
    db_User.Show_ListUser();
    // return 0;
    // cout << "Chao mung" << endl;
    // cout << "Ban muon lam gi" << endl;
    // cout << "1. dang nhap User" << endl;
    // cout << "2. dang nhap admin" << endl;
    // cout << "3. dang ky" << endl;
    // int choose;
    // cin >> choose;
    // string tk;
    // string mk;
    // // cin>>tk>>mk;
    // // cout<<db_User.Sign_in(tk, mk);
    // if (choose == 1) {
    //     while (true) {
    //         cout << "Nhap tk: ";
    //         cin >> tk;
    //         cout << endl;
    //         cout << "Nhap mk: ";
    //         cin >> mk;
    //         cout << endl;
    //         if (db_User.Sign_in(tk, mk) == 1) {
    //             // User Object_user = db_User.Return_User(tk);
    //             break;
    //         }
    //     }
    //     // User Object_user = db_User.Return_User(tk);
    //     // // Object_user.Show_User();
    //     // Object_user.Buy("Csgo");
    //     // Object_user.Buy("HollowKnight");
    //     // Object_user.Buy("HollowKnight");
    //     // Object_user.Buy("HollowKnight");
    //     // Object_user.Buy("HollowKnight");
    //     // Object_user.Show_User(db_Game);
    // } else if (choose == 2) {
    //     while (true) {
    //         cout << "Nhap tk: ";
    //         cin >> tk;
    //         cout << endl;
    //         cout << "Nhap mk: ";
    //         cin >> mk;
    //         cout << endl;
    //         if (Admin.Login_admin(tk, mk)) {
    //             // User Object_user = db_User.Return_User(tk);
    //             break;
    //         }
    //     }
    //     cout << "Ban muon lam gi" << endl;
    //     cout << "1. Xem kho" << endl;
    //     cout << "2. Xem danh sach nguoi dung" << endl;
    //     cout << "3. Them Game vao kho" << endl;
    //     cout << "4. Cap nhat thong tin Game" << endl;
    //     cout << "5. Xoa Game" << endl;
    //     int choose_admin;
    //     cin >> choose_admin;
    // } else if (choose == 3) {
    //     cout << "Nhap tk: ";
    //     cin >> tk;
    //     cout << endl;
    //     cout << "Nhap mk: ";
    //     cin >> mk;
    //     db_User.Sign_up(tk, mk);
    //     db_User.Show_ListUser();
    // }
}