#pragma once
#include <iostream>
#include "game.hpp"

using namespace std;

class NodeQ //clasa Node creata pentru Queue
{
public:
    Game data;
    NodeQ *next;
};
