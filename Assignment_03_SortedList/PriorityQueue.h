#pragma once
#include<string>
#include<exception>
#include"Call.h"

class FullQueue {
public:
	std::string Error() { return "The Queue is full."; }
};
//Exception class
class EmptyQueue {
public:
	std::string Error() { return "The Queue is empty."; }
};


class PriorityQueue
{
	struct NodeType {
		Call info;
		NodeType* next = nullptr;
	};

public:
	PriorityQueue();
	~PriorityQueue();
	bool Enqueue(Call);
	void Dequeue();
	bool is_full();
	void make_empty();
	bool is_empty();
	int get_length();
	Call Top();
	


private:
	NodeType* front;
	NodeType* rear;
	int length;
};

