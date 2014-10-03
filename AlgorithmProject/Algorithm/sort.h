#include "array.h"

template<class T>
int FindMedianOfThree(Array<T>& _array, int _first, int _size, int(*compare)(T,T))
{
	int last = _first + _size - 1;
	int mid = _first + (_size / 2);

	if(compare(_array[_first], _array[mid]) < 0 && 
		compare(_array[_first], _array[last]) < 0)
	{
		if(compare(_array[mid], _array[last]) < 0)
			return mid;
		else
			return last;
	}

	if(compare(_array[_first], _array[mid]) < 0 && 
		compare(_array[_first], _array[last]) < 0)
	{
		if(compare(_array[mid], _array[last]) < 0)
			return mid;
		else
			return last;
	}

	if(compare(_array[mid], _array[_first]) < 0)
		return mid;
	else
		return _first;
}
