#include "stack.hpp"
#include <sstream>
#include <iomanip>

Stack::Stack()
{
	link = NULL;
}

Stack::~Stack()
{
	Node *temp;
	while (link != NULL)
	{
		temp = link;
		link = link->next;
		delete temp;
	}
	delete[] link;
}

void Stack::Push(Team team)
{

	Node *temp = new Node();
	temp->data = team;
	if (link == NULL)
	{
		temp->next = NULL;
	}
	else
	{
		temp->next = link;
	}
	link = temp;
}

void Stack::Pop()
{

	if (link == NULL)
		return;
	else
	{
		Node *temp = link;
		link = link->next;
		free(temp);
	}
}

string Stack::display_stack()
{
	string string_return;

	if (link == NULL)
	{
		cout << "Stiva e goala" << endl;
	}
	else
	{
		Node *temp = link;
		while (temp != NULL)
		{
			string first_part(34 - temp->data.get_teamName().length(), ' ');
			std::stringstream second_part;
			second_part << std::fixed << std::setprecision(2) << temp->data.get_score();
			string_return.append(temp->data.get_teamName()).append(first_part).append("-  ").append(second_part.str()).append("\n");

			temp = temp->next;
		}
	}
	return string_return;
}

Node *Stack::get_link()
{
	return link;
}
