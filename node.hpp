#pragma once
#include <iostream>
#include "team.hpp"

using namespace std;

class Node // clasa Node pentru crearea List
{
public:
    Team data;
    Node *next;
};
