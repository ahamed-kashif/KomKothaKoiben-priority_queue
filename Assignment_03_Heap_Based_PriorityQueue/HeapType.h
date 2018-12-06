#pragma once
#include<vector>

using namespace std;

template<class ItemType>
class HeapType
{
public:
	HeapType();
	~HeapType();
	virtual void reheap_up(int root, int bottom);
	virtual void reheap_down(int root, int bottom);
	void swap(ItemType first, ItemType second);
private:

	vector<ItemType>* items=nullptr;

};

