/*----------------------------------------------------------------
이름 : 써큘러큐 클래스
작업자 : 조이현
설명 : 써큘러큐를 템플릿 클래스로 정의
만든날짜 : 2013.12.21
화일명 : queue.h
----------------------------------------------------------------*/
#pragma once

#include "array.h"

template<class T>
class CircularQueue
{
private:
	Array<T> data;		//Array클래스 데이터
	int front;
	int count;

/*----------------------------------------------------------------
이름: CircularQueue::CircularQueue
설명: 기본 생성자. 
		사이즈가 없이 생성되는것을 방지하기위해 Private속성으로 선언.
----------------------------------------------------------------*/
	CircularQueue(){}	

public:

/*----------------------------------------------------------------
이름: CircularQueue::CircularQueue
설명: 입력받은 두 값을 비교하는 템플릿 함수
인자값: _size : 써큘러큐의 사이즈
----------------------------------------------------------------*/
	CircularQueue(int _size):data(_size)
	{
		front = 0;
		count = 0;
	}

/*----------------------------------------------------------------
이름: CircularQueue::Enqueue
설명: 데이터를 큐에 입력한다.
인자값: _data : 큐에 입력하려는 값
리턴값:	성공여부.
----------------------------------------------------------------*/
	bool Enqueue(T _data)
	{
		//현재 포화상태가 아니라면
		if(data.Size() != count)
		{
			//시작위치와 현재의 갯수를 더한 위치에 값을 입력한다.
			data.Insert(_data, count + front);
			count++; //갯수를 증가시킨다.
			return true;
		}

		return false;
	}

/*----------------------------------------------------------------
이름: CircularQueue::Dequeue
설명: 데이터를 큐에서 꺼낸다.
----------------------------------------------------------------*/
	void Dequeue()
	{
		if(count > 0)
		{
			count--;		//갯수를 감소시킨다.
			front++;	//시작위치를 이동시킨다.

			//시작위치가 데이터의 사이즈와 동일하다면 0을 입력한다.
			if(front == data.Size())
				front = 0;
		}
	}

/*----------------------------------------------------------------
이름: CircularQueue::FrontData
설명: 시작위치의 데이터를 알아낸다.
리턴값:	시작위치의 데이터
----------------------------------------------------------------*/
	T& FrontData()
	{
		return data.[front];
	}

/*----------------------------------------------------------------
이름: CircularQueue::Front
설명: 시작위치값을 알아낸다.
리턴값:	시작위치
----------------------------------------------------------------*/
	int Front()
	{
		return front;
	}

/*----------------------------------------------------------------
이름: CircularQueue::Count
설명: 입력된 데이터의 갯수를 알아낸다.
리턴값:	데이터의 갯수
----------------------------------------------------------------*/
	int Count()
	{
		return count;
	}

/*----------------------------------------------------------------
이름: CircularQueue::operator[]
설명: 큐의 값을 배열과 같이 접근한다.
리턴값:	해당 인덱스의 큐값
----------------------------------------------------------------*/
	T& operator[](int _index)
	{
		assert(_index < count && "입력값이 사이즈를 초과했습니다.");
		return data[(_index + front) % data.Size()];
	}

/*----------------------------------------------------------------
이름: CircularQueue::GetData
설명: 큐의 데이터(배열)를 알아낸다.
리턴값:	큐의 데이터 값
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