#include "HeapType.h"



template<class ItemType>
HeapType<ItemType>::HeapType()
{
}


template<class ItemType>
HeapType<ItemType>::~HeapType()
{
}

template<class ItemType>
void HeapType<ItemType>::swap(ItemType first, ItemType second)
{
	ItemType temp;
	temp = first;
	first = second;
	second = temp;
}

