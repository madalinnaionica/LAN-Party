#pragma once
#include <iostream>
#include "node.hpp"

using namespace std;

class List
{
private:
    Node *head;

public:
    List();
    ~List();
    void add_node(Team);
    void display_list();
    void delete_node(Team);
    string print_teams_names();
    Team lowest_score();
    Node *get_head();
};
