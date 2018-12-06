#pragma once
#include<string>
#include<exception>

class FullQueue {
public:
	std::string Error() { return "The Queue is full."; }
};
//Exception class
class EmptyQueue {
public:
	std::string Error() { return "The Queue is empty."; }
};


template<class ItemType>
class PriorityQueue
{
	struct NodeType {
		ItemType info = ItemType();
		NodeType* next = nullptr;
	};

public:
	PriorityQueue();
	~PriorityQueue();
	bool Enqueue(ItemType);
	void Dequeue();
	bool is_full();
	void make_empty();
	bool is_empty();
	int get_length();
	ItemType Top();
	


private:
	NodeType* front;
	NodeType* rear;
	int length;
};

