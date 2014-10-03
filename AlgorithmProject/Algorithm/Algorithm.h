#pragma once

#include <Windows.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

#include "array.h"
#include "bitvector.h"
#include "sort.h"

namespace Algorithm
{
	enum EDATA_TYPE
	{
		eArray = 1,
		eBitvector,
		eQuickSort,
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
	}

	int Run();
}