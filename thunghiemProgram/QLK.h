#include <iostream>
#include "Game.h"
#pragma once


using namespace std;

class QLK{
    private:
        Game *arr;
        int len;
    public:
        // QLK();
        QLK(string);
        ~QLK();
        void Length(int);
        int Length();
        void Add(Game);
        int Search(string);
        void Delete(Game, int);
        void Sort(string);
        void Update_data(Game, int);
        void Update_numberS(bool, int, int);
        Game Return_object(int);
        void Show();
};
