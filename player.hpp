#pragma once
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Player
{
private:
    string firstName;
    string secondName;
    int points;

public:
    Player();
    Player(string, string, int);
    void afisare();
    string get_firstName();
    string get_secondName();
};
