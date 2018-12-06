#pragma once
#include<vector>
#include "Call.h"

using namespace std;


class HeapType
{
public:
	HeapType();
	~HeapType();
	virtual void reheap_up(int root, int bottom);
	virtual void reheap_down(int root, int bottom);
	void swap(Call first, Call second);

	vector<Call> item;
	int length=0;

};

