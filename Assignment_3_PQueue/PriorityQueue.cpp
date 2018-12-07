#include "PriorityQueue.h"



PriorityQueue::PriorityQueue()
{
	calls = new Call[max_call];
	length = 0;
}

PriorityQueue::PriorityQueue(int maximumCall)
{
	calls = new Call[maximumCall];
	max_call = maximumCall;
	length = 0;
}


PriorityQueue::~PriorityQueue()
{
}

void PriorityQueue::swap(Call& one, Call& two)
{
	Call temp;
	temp = one;
	one = two;
	two = temp;
}

void PriorityQueue::reheapUp(int root, int bottom)
{
	if (root < bottom)
	{
		int parent;
		parent = (bottom - 1) / 2;
		if (calls[parent].get_relation_type() > calls[bottom].get_relation_type())
		{
			swap(calls[parent], calls[bottom]);
			reheapUp(root, parent);
		}
		else if (calls[parent].get_relation_type() == calls[bottom].get_relation_type())
		{
			if (calls[parent].get_call_duration() < calls[bottom].get_call_duration())
			{
				swap(calls[parent], calls[bottom]);
				reheapUp(root, parent);
			}
		}
	}
}

void PriorityQueue::reheapDown(int root, int bottom)
{
	if (calls != nullptr)
	{
		int maxC;
		int leftC = (2 * root) + 1;
		int rightC = (2 * root) + 2;

		if (leftC <= bottom)
		{
			if (leftC == bottom)
			{
				maxC = leftC;
			}
			else
			{
				if (root < rightC)
				{
					if (calls[rightC].get_relation_type() < calls[leftC].get_relation_type())
					{
						maxC = rightC;
					}
					else if (calls[rightC].get_relation_type() == calls[leftC].get_relation_type())
					{
						if (calls[rightC].get_call_duration() > calls[leftC].get_call_duration())
						{
							maxC = rightC;
						}
						else
							maxC = leftC;
					}
					else
						maxC = leftC;
				}
			}
			if (calls[root].get_relation_type() > calls[maxC].get_relation_type())
			{
				swap(calls[root], calls[maxC]);
				reheapDown(maxC, bottom);
			}
			else if (calls[root].get_relation_type() == calls[maxC].get_relation_type())
			{
				if (calls[root].get_call_duration() < calls[maxC].get_call_duration())
				{
					swap(calls[root], calls[maxC]);
					reheapDown(maxC, bottom);
				}
			}
		}
	}
}

void PriorityQueue::enqueue(Call newCall)
{
	if (is_full())
	{
		Call* tempCalls = new Call[2*max_call];
		for (int index = 0; index < length; index++)
		{
			tempCalls[index] = calls[index];
		}
		max_call *= 2;
		delete[] calls;
		calls = tempCalls;
	}

	length++;
	calls[length - 1] = newCall;
	reheapUp(0, length - 1);
}

void PriorityQueue::dequeue(Call& removedCall)
{
	removedCall = calls[0];
	calls[0] = calls[length - 1];
	length--;
	reheapDown(0, length - 1);
}

bool PriorityQueue::is_full()
{
	return (length==max_call);
}

bool PriorityQueue::is_empty()
{
	return (length==0);
}

int PriorityQueue::get_length()
{
	return length;
}
