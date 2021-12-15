#include "player.hpp"

Player::Player()
{
    firstName = "null";
    secondName = "null";
    points = 0;
}

//constructor cu parametrii
Player::Player(string myFirstName, string mySecondName, int myPoints)
{
    firstName = myFirstName;
    secondName = mySecondName;
    points = myPoints;
}

void Player::afisare()
{
    cout << firstName << " ";
    cout << secondName << " ";
    cout << points << endl;
}

string Player::get_firstName()
{
    return firstName;
}

string Player::get_secondName()
{
    return secondName;
}
