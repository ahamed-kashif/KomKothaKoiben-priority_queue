#include "HeapType.h"




HeapType::HeapType()
{
}


HeapType::~HeapType()
{
}


void HeapType::swap(Call first, Call second)
{
	Call temp;
	temp = first;
	first = second;
	second = temp;
}

