#include "queue.hpp"
#include "nodeQ.hpp"

Queue::Queue()
{
	front = NULL;
	rear = NULL;
}

Queue::~Queue()
{
	NodeQ *temp;
	while (front != NULL)
	{
		temp = front;
		front = front->next;
		delete temp;
	}
	rear = NULL;
}

void Queue::enQueue(Game game)
{
	NodeQ *temp = new NodeQ();
	temp->data = game;
	temp->next = NULL;
	if (front == NULL && rear == NULL)
	{
		front = rear = temp;
		return;
	}
	rear->next = temp;
	rear = temp;
}

void Queue::deQueue()
{
	NodeQ *temp = front;
	if (front == NULL)
		return;
	if (front == rear)
	{
		front = rear = NULL;
	}
	else
	{
		front = front->next;
	}
	delete temp;
}

string Queue::display_queue()
{
	string string_return;
	if (front == NULL)
	{
		cout << "Coada e goala." << endl;
	}
	else
	{
		NodeQ *temp = front;
		while (temp != NULL)
		{
			string_return.append(temp->data.afisare());
			temp = temp->next;
		}
	}
	return string_return;
}

NodeQ *Queue::get_front()
{
	return front;
}
