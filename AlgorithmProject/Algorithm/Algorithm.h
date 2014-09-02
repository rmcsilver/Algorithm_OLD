#pragma once

namespace Algorithm
{
	enum EDATA_TYPE
	{
		eArray = 1,
		eMax
	};

	template<class T>
	class Array
	{
	private:
		T* ArrayData;
		int ArraySize;
	public:
		Array(int size)
		{
			ArrayData = new T[size];
			ZeroMemory(ArrayData, sizeof(T) * size);
			ArraySize =  size;
		}
		~Array()
		{
			if(ArrayData != 0)	delete [] ArrayData;
			ArrayData = 0;
		}

		T& operator[](int index)
		{
			return ArrayData[index];
		}

		int Size()
		{
			return ArraySize;
		}

		void Resize(int size)
		{
			T* NewArray = new T[size];
			ZeroMemory(NewArray, sizeof(T) * size);

			if(NewArray == 0)	return;

			int count = ArraySize;
			if(size < ArraySize)	count = size;

			for(int i = 0; i < count; i++)
				NewArray[i] = ArrayData[i];

			ArraySize = size;

			if(ArrayData != 0)	delete [] ArrayData;

			ArrayData = NewArray;
		}

		void Insert(T Item, int index)
		{
			for(int i = ArraySize - 1; i > ArraySize; i--)
				ArrayData[i] = ArrayData[i-1];

			ArrayData[index] = Item;
		}

		void Remove(int index)
		{
			for(int i=index + 1; i < ArraySize; i++)
				ArrayData[i - 1] = ArrayData[i];
		}

		operator T*()
		{
			return ArrayData;
		}

	};

	int Run();
}