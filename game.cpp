#include "game.hpp"
#include <string>

Game::Game()
{
}

Game::Game(Team team1, Team team2)
{
    t1 = team1;
    t2 = team2;
}

Game::~Game()
{
}

Game::Game(const Game &game)
{
    t1 = game.t1;
    t2 = game.t2;
}

Game &Game::operator=(const Game &game)
{
    t1 = game.t1;
    t2 = game.t2;
    return *this;
}

Team Game::get_team1()
{
    return t1;
}

Team Game::get_team2()
{
    return t2;
}

string Game::afisare()
{

    string return_string;
    string first_part(33 - t1.get_teamName().length(), ' ');
    string second_part(68 - t2.get_teamName().length() - 35, ' ');

    return_string.append(t1.get_teamName()).append(first_part).append("-").append(second_part).append(t2.get_teamName()).append("\n");

    return return_string;
}

Team Game::get_winner()
{
    if (t1.get_score() == t2.get_score())
    {
        t2.set_score(t2.get_score() + 1.0);
        return t2;
    }
    if (t1.get_score() > t2.get_score())
    {
        t1.set_score(t1.get_score() + 1.0);
        return t1;
    }
    t2.set_score(t2.get_score() + 1.0);
    return t2;
}

Team Game::get_looser()
{
    if (t1.get_score() < t2.get_score())
        return t1;
    return t2;
}


