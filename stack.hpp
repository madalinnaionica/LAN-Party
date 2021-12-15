#pragma once
#include <iostream>
#include "node.hpp"

class Stack
{
private:
	Node *link;

public:
	Stack();
	~Stack();
	void Push(Team);
	void Pop();
	string display_stack();
	Node *get_link();
};
