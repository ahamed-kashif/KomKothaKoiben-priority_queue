#include "PriorityQueue.h"




PriorityQueue::PriorityQueue()
{
	front = nullptr;
	rear = nullptr;
	length = 0;
}


PriorityQueue::~PriorityQueue()
{
	make_empty();
}


bool PriorityQueue::Enqueue(Call newItem)
{
	if (is_full())
		return false;

	NodeType* newNode = new NodeType;
	newNode->info = newItem;
	NodeType* curr = front;
	NodeType* prev = nullptr;
	bool posFound = false;

	while (curr != nullptr && !posFound) {
		if (curr->info.get_relation_type() < newItem.get_relation_type()) {
			prev = curr;
			curr = curr->next;
		}
		else if (curr->info.get_relation_type() == newItem.get_relation_type())
		{
			if (curr->info.get_call_duration() >= curr->info.get_call_duration())
			{
				posFound = true;
				newNode->next = curr;
				if (prev == nullptr) {
					front = newNode;
				}
				else {
					prev->next = newNode;
				}
			}
			else
			{
				posFound = true;
				prev = curr;
				curr = curr->next;
				newNode->next = curr;
				if (prev == nullptr) {
					front = newNode;
				}
				else {
					prev->next = newNode;
				}

			}
			
			
		}
		else {
			posFound = true;
			newNode->next = curr;
			if (prev == nullptr) {
				front = newNode;
			}
			else {
				prev->next = newNode;
			}
		}
	}
	if (!posFound)
	{
		posFound = true;
		newNode->next = curr;
		if (prev == nullptr) {
			front = newNode;
		}
		else {
			prev->next = newNode;
			
		}
		rear = newNode;
	}
	length++;
}


void PriorityQueue::Dequeue()
{
	if (is_empty()) {
		throw EmptyQueue();
	}
	else {
		NodeType* dequeuedNode = front;

		front = front->next;
		

		if (front == nullptr)
			rear = nullptr;

		delete dequeuedNode;
		length--;
	}
}


bool PriorityQueue::is_full()
{
	try {
		NodeType* newNode = new NodeType();
		delete newNode;
	}
	catch (const std::bad_alloc&) {
		return true;
	}
	return false;
}


void PriorityQueue::make_empty()
{
	
	while (!is_empty())
		Dequeue();
}


bool PriorityQueue::is_empty()
{
	return ((length == 0) && (front == nullptr) && (rear == nullptr));
}


int PriorityQueue::get_length()
{
	return length;
}


Call PriorityQueue::Top()
{
	return front->info;
}


