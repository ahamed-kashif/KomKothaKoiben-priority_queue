#pragma once
#include"Call.h"
class PriorityQueue
{
public:

	PriorityQueue();
	PriorityQueue(int);
	~PriorityQueue();
	void swap(Call&,Call&);
	void reheapUp(int, int);
	void reheapDown(int, int);
	void enqueue(Call);
	void dequeue(Call&);
	bool is_full();
	bool is_empty();
	int get_length();

private:
	Call* calls;
	int max_call = 100;
	int length;

};

