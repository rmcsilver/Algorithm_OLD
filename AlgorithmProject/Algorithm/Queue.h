/*----------------------------------------------------------------
�̸� : ��ŧ��ť Ŭ����
�۾��� : ������
���� : ��ŧ��ť�� ���ø� Ŭ������ ����
���糯¥ : 2013.12.21
ȭ�ϸ� : queue.h
----------------------------------------------------------------*/
#pragma once

#include "array.h"

template<class T>
class CircularQueue
{
private:
	Array<T> data;		//ArrayŬ���� ������
	int front;
	int count;

/*----------------------------------------------------------------
�̸�: CircularQueue::CircularQueue
����: �⺻ ������. 
		����� ���� �����Ǵ°��� �����ϱ����� Private�Ӽ����� ����.
----------------------------------------------------------------*/
	CircularQueue(){}	

public:

/*----------------------------------------------------------------
�̸�: CircularQueue::CircularQueue
����: �Է¹��� �� ���� ���ϴ� ���ø� �Լ�
���ڰ�: _size : ��ŧ��ť�� ������
----------------------------------------------------------------*/
	CircularQueue(int _size):data(_size)
	{
		front = 0;
		count = 0;
	}

/*----------------------------------------------------------------
�̸�: CircularQueue::Enqueue
����: �����͸� ť�� �Է��Ѵ�.
���ڰ�: _data : ť�� �Է��Ϸ��� ��
���ϰ�:	��������.
----------------------------------------------------------------*/
	bool Enqueue(T _data)
	{
		//���� ��ȭ���°� �ƴ϶��
		if(data.Size() != count)
		{
			//������ġ�� ������ ������ ���� ��ġ�� ���� �Է��Ѵ�.
			data.Insert(_data, count + front);
			count++; //������ ������Ų��.
			return true;
		}

		return false;
	}

/*----------------------------------------------------------------
�̸�: CircularQueue::Dequeue
����: �����͸� ť���� ������.
----------------------------------------------------------------*/
	void Dequeue()
	{
		if(count > 0)
		{
			count--;		//������ ���ҽ�Ų��.
			front++;	//������ġ�� �̵���Ų��.

			//������ġ�� �������� ������� �����ϴٸ� 0�� �Է��Ѵ�.
			if(front == data.Size())
				front = 0;
		}
	}

/*----------------------------------------------------------------
�̸�: CircularQueue::FrontData
����: ������ġ�� �����͸� �˾Ƴ���.
���ϰ�:	������ġ�� ������
----------------------------------------------------------------*/
	T& FrontData()
	{
		return data.[front];
	}

/*----------------------------------------------------------------
�̸�: CircularQueue::Front
����: ������ġ���� �˾Ƴ���.
���ϰ�:	������ġ
----------------------------------------------------------------*/
	int Front()
	{
		return front;
	}

/*----------------------------------------------------------------
�̸�: CircularQueue::Count
����: �Էµ� �������� ������ �˾Ƴ���.
���ϰ�:	�������� ����
----------------------------------------------------------------*/
	int Count()
	{
		return count;
	}

/*----------------------------------------------------------------
�̸�: CircularQueue::operator[]
����: ť�� ���� �迭�� ���� �����Ѵ�.
���ϰ�:	�ش� �ε����� ť��
----------------------------------------------------------------*/
	T& operator[](int _index)
	{
		assert(_index < count && "�Է°��� ����� �ʰ��߽��ϴ�.");
		return data[(_index + front) % data.Size()];
	}

/*----------------------------------------------------------------
�̸�: CircularQueue::GetData
����: ť�� ������(�迭)�� �˾Ƴ���.
���ϰ�:	ť�� ������ ��
----------------------------------------------------------------*/
	Array<T>& GetData()
	{
		return data; 
	}

};

/*
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
*/