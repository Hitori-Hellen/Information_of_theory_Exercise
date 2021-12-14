#include <iostream>
#pragma once
using namespace std;

class Game{
    protected:
        string _Name;
        string _Genre;
        string _Developer;
        int _ReleaseYear;
        int _Price;
        int _NumberS;
        double _Rating;
    public:
        Game();
        Game(string, string, string, int, int, int, double);
        ~Game();
        void setName(string);
        void setGen(string);
        void setDev(string);
        void setYear(int);
        void setPrice(int);
        void setSoluong(int);
        void setRating(double);
        string getName();
        string getGen();
        string getDev();
        int getYear();
        int getPrice();
        int getSoluong();
        double getRating();
        void Show();
};