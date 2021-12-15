#pragma once
#include <string>
#include <iostream>
#include "player.hpp"

using namespace std;

class Team
{
private:
    string teamName;
    int numberOfPlayers;
    float totalScore;
    Player *players;

public:
    Team *next;
    Team();
    Team(string, int, float, Player *);
    ~Team();
    Team &operator=(const Team &);
    Team(const Team &);
    float get_score();
    void afisare();
    string get_teamName();
    Player *get_players();
    void set_score(float);
};
