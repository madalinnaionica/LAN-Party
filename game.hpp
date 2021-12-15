#pragma once
#include <iostream>
#include "team.hpp"
using namespace std;

class Game
{
private:
    Team t1;
    Team t2;

public:
    Game(Team, Team);
    ~Game();
    Game();
    Game &operator=(const Game &);
    Game(const Game &);
    Team get_team1();
    Team get_team2();
    string afisare();
    Team get_winner();
    Team get_looser();
};