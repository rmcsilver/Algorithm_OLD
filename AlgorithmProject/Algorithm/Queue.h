#pragma once

#include "array.h"

template<class T>
class CircularQueue
{
private:
	Array<T> data;
	int front;
	int count;

public:
	CircularQueue(int _size):data(_size)
	{
		front = 0;
		count = 0;
	}

	bool Enqueue(T _data)
	{
		if(data.Size() != count)
		{
			data.Insert(_data, count + front);
			count++;
			return true;
		}

		return false;
	}

	void Dequeue()
	{
		if(count > 0)
		{
			count--;
			front++;
			if(front == data.Size())
				front = 0;
		}
	}

	T& FrontData()
	{
		return data.[front];
	}

	int Front()
	{
		return front;
	}

	int Count()
	{
		return count;
	}

	T& operator[](int _index)
	{
		return data[(_index + front) % data.Size()];
	}

	Array<T>& GetData()
	{
		return data; 
	}

};