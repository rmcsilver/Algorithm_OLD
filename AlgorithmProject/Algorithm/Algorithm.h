#pragma once

#include <Windows.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

#include "array.h"
#include "bitvector.h"
#include "sort.h"
#include "Queue.h"

namespace Algorithm
{
	enum EDATA_TYPE
	{
		eArray = 1,
		eBitvector,
		eQuickSort,
		eCircularQueue,
		eArray2D,
		eArray3D,
		eMax
	};

	template<class DataType>
	void PrintArray( Array<DataType>& p_array )
	{
		int index;

		for( index = 0; index < p_array.Size(); index++ )
		{
			std::cout << p_array[index] << ", ";
		}
		std::cout << std::endl;
	}

	template<class T>
	void PrintCircularQueue( CircularQueue<T>& _queue )
	{
		int index;

		for( index = 0; index < _queue.Count(); index++ )
		{
			std::cout << _queue[index] << ", ";
		}
		std::cout << std::endl;
	}

	template<class T>
	void PrintVector( std::vector<T>& _data )
	{
		std::vector<T>::iterator iter;

		for( iter = _data.begin(); iter != _data.end(); ++iter )
		{
			std::cout << (*iter) << ", ";
		}
		std::cout << std::endl;

	}
	int Run();
}