#pragma once

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

template<class T>
void QuickSort(Array<T>& _array, int _first, int _size, int (*compare)(T,T))
{
	T pivot;
	int last = _first + _size - 1;
	int lower = _first;
	int higher = last;
	int mid;

	if(_size > 1)
	{
		mid = FindMedianOfThree(_array, _first, _size, compare);
		pivot = _array[mid];

		_array[mid] = _array[_first];

		while(lower < higher)
		{
			while(compare(pivot, _array[higher]) < 0 && lower < higher)
				higher--;

			if(higher != lower)
			{
				_array[lower] = _array[higher];
				lower++;
			}

			while(compare(pivot, _array[lower]) > 0 && lower < higher)
				lower++;

			if(higher != lower)
			{
				_array[higher] = _array[lower];
				higher--;
			}
		}

		_array[lower] = pivot;

		QuickSort(_array, _first, lower - _first, compare);
		QuickSort(_array, lower + 1, last - lower, compare);
	}

}