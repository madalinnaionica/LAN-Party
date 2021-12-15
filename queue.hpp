#pragma once
#include <iostream>
#include "nodeQ.hpp"
#include "game.hpp"
using namespace std;

class Queue
{
private:
	NodeQ *front; 
	NodeQ *rear;

public:
	Queue();
	~Queue();
	void enQueue(Game);
	void deQueue();
	string display_queue();
	NodeQ *get_front();
};
