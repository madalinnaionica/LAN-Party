#include "list.hpp"

List::List()
{
    head = NULL;
}

void List::add_node(Team team)
{
    Node *new_node = new Node();
    new_node->data = team;
    new_node->next = head;
    head = new_node;
}

void List::display_list()
{
    if (head == NULL)
    {
        cout << "Lista e goala." << endl;
    }
    else
    {
        Node *temp = head;

        while (temp != NULL)
        {
            temp->data.afisare();
            temp = temp->next;
        }
    }
}

string List::print_teams_names()// functie pentru afisarea numelor echipelor din lista
{
    string return_string;

    if (head == NULL)
    {
        cout << "Lista e goala." << endl;
    }
    else
    {
        Node *temp = head;

        while (temp != NULL)
        {
            string teamName = temp->data.get_teamName();
            return_string.append(teamName).append("\n");
            temp = temp->next;
        }
    }

    return return_string;
}

void List::delete_node(Team team)
{
    Node *current = head;
    Node *previous = NULL;

    if (current != NULL && current->data.get_teamName().compare(team.get_teamName()) == 0)
    {
        head = current->next;
        delete current;
        return;
    }

    while (current->data.get_teamName().compare(team.get_teamName()) != 0)
    {

        previous = current;
        current = current->next;
    }
    if (current == NULL)
    {

        return;
    }

    previous->next = current->next;
    delete current;
}

List::~List()
{
    Node *node;

    while (head != NULL)
    {
        node = head;
        head = head->next;
        delete node;
    }

    delete[] head;
}

Team List::lowest_score()
{
    Team low_team;
    float min_score = 100000;
    Node *temp = head;

    while (temp != NULL)
    {
        if (temp->data.get_score() < min_score)
        {
            min_score = temp->data.get_score();
        }
        temp = temp->next;
    }

    temp = head;
    while (temp != NULL)
    {
        if (temp->data.get_score() == min_score)
        {
            return (temp->data);
        }
        temp = temp->next;
    }

    return low_team;
}

Node *List::get_head()
{
    return head;
}