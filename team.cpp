#include "team.hpp"

Team::Team()
{
    teamName = "null";
    numberOfPlayers = 0;
    totalScore = 0;
    players = NULL;
}

Team::Team(string myTeamName, int myNumberOfPlayers, float myTotalScore, Player *playersList)
{
    teamName = myTeamName;
    numberOfPlayers = myNumberOfPlayers;
    totalScore = myTotalScore;
    players = new Player[myNumberOfPlayers];

    for (int i = 0; i < myNumberOfPlayers; i++)
    {
        players[i] = playersList[i];
    }
}

Team::Team(const Team &team)
{
    teamName = team.teamName;
    numberOfPlayers = team.numberOfPlayers;
    totalScore = team.totalScore;

    if (team.numberOfPlayers > 0)
    {
        players = new Player[team.numberOfPlayers];

        for (int i = 0; i < team.numberOfPlayers; i++)
            players[i] = team.players[i];
    }
}

Team &Team::operator=(const Team &team)
{
    teamName = team.teamName;
    numberOfPlayers = team.numberOfPlayers;
    totalScore = team.totalScore;

    if (team.numberOfPlayers > 0)
    {
        players = new Player[team.numberOfPlayers];

        for (int i = 0; i < team.numberOfPlayers; i++)
            players[i] = team.players[i];
    }
    return *this;
}

Team::~Team()
{
    delete[] players;
}

void Team::afisare()
{
    cout << teamName << endl;
    cout << numberOfPlayers << endl;
    cout << totalScore << endl;

    for (int i = 0; i < numberOfPlayers; i++)
    {
        this->players[i].Player::afisare();
    }
}

string Team::get_teamName()
{
    return teamName;
}

Player *Team::get_players()
{
    return players;
}

float Team::get_score()
{
    return totalScore;
}

void Team::set_score(float my_score)
{
    totalScore = my_score;
}
