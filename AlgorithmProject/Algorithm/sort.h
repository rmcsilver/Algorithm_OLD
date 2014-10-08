/*----------------------------------------------------------------
이름 : 정렬 라이브러리
작업자 : 조이현
설명 : 정렬관련 함수들을 정의
만든날짜 : 2013.12.21
화일명 : sort.h
----------------------------------------------------------------*/
#pragma once

#include <vector>

//정렬타입
namespace SortOrder
{
	enum Type
	{
		Ascending_Order = 0,	//오름차순타입
		Descending_Order,		//내림차순타입
	};
}

namespace SortLib
{
 
/*----------------------------------------------------------------
이름: Compare
설명: 입력받은 두 값을 비교하는 템플릿 함수
인자값: _value1, _value2 : 비교하려는 두 값.
		_order : 비교하려는 방법(오름차순, 내림차순 선택)
리턴값:	비교 값이 정렬 순서에 맞으면 1, 다르다면 -1, 같다면 0
----------------------------------------------------------------*/
template<class T>
int Compare(const T& _value1, const T& _value2, SortOrder::Type _order)
{
	switch(_order)
	{
		case SortOrder::Ascending_Order:
			{
				if(_value1 < _value2)		return 1;
				else if(_value1 > _value2)	return -1;
			}break;

		case SortOrder::Descending_Order:
			{
				if(_value1 > _value2)		return 1;
				else if(_value1 < _value2)	return -1;
			}break;
		default:
			{
				if(_value1 < _value2)		return 1;
				else if(_value1 > _value2)	return -1;
			}break;
	}

	return 0;
}

/*----------------------------------------------------------------
이름: FindMedian
설명: 벡터 전체 데이터에서 처음,중간,마지막의 숫자 중에 중간값을 찾는 템플릿 함수
인자값: _data : 벡터 전체 데이터
		_first : 시작위치
		_size : 사이즈
		_order : 정렬방법
리턴값:	중간값으로 선택된 값의 위치
----------------------------------------------------------------*/
template<class T>
int FindMedian(std::vector<T>& _data, int _first, int _size, SortOrder::Type _order)
{
	int _last = _first + _size - 1;
	int _mid = _first + (_size / 2);

	T first = _data.at(_first);
	T mid = _data.at(_mid);
	T last = _data.at(_last);

	//1.첫번째값보다 중간값, 마지막값이 크다면,
	if( (Compare(first, mid, _order) > 0) && (Compare(first, last, _order) > 0))
	{
		//중간값과 마지막값 중에 작은 값을 선택한다.
		if(Compare(mid, last, _order) > 0)	return _mid;
		else return _last;
	}

	//2.중간값보다 첫번째값, 마지막값이 크다면,
	if( (Compare(mid, first, _order) > 0) && (Compare(mid, last, _order) > 0))
	{
		//첫번째값과 마지막값 중에 작은 값을 선택한다.
		if(Compare(first, last, _order) > 0)	return _first;
		else return _last;
	}

	//3.마지막값보다 첫번째값, 중간값이 크다면, 첫번째값과 중간값 중에 작은 값을 선택한다.
	if(Compare(first, mid, _order) > 0)	return _first;
	else return _mid;
}

/*----------------------------------------------------------------
이름: QSort
설명: 벡터 전체 데이터를 퀵소트하는 템플릿 함수.
		재귀함수이며 FindMedian()함수를 사용하여 최악의 정렬시간을 개선한다.
인자값: _data : 벡터 전체 데이터
		_order : 정렬방법
		_first : 시작위치
		_size : 사이즈
리턴값:	중간값으로 선택된 값의 위치
----------------------------------------------------------------*/
template<class T>
void QSort(std::vector<T>& _data, SortOrder::Type _order = SortOrder::Ascending_Order, int _first = -1, int _size = -1)
{
	//디폴트 인수값은 벡터 전체를 범위로 한다.
	if(_first == -1 || _size == -1)
	{
		_first = 0;
		_size = _data.size();
	}

	T pivot;
	int last = _first + _size - 1;
	int lower = _first;
	int higher = last;
	int mid;

	if(_size > 1)
	{
		//피벗이 될 중간값을 찾는다.
		mid = FindMedian(_data, _first, _size, _order);
		pivot = _data[mid];

		//첫번째 자리를 비우기 위해 선택된 값자리에 첫번째 값을 입력한다.
		_data[mid] = _data[_first];

		while(lower < higher)
		{
			//뒤에서부터 앞으로 피벗과의 정렬방법에 맞는수가 있는지 검색한다.
			while(Compare(pivot, _data[higher], _order) > 0 && lower < higher)
				higher--;

			//앞과 뒤가 만나지 않았다면 
			if(higher != lower)
			{
				//값을 교체한다.
				_data[lower] = _data[higher];
				lower++;
			}
			
			//앞에서부터 뒤까지 피벗과의 정렬방법에 반대되는 수가 있는지 검색한다.
			while(Compare(pivot, _data[lower], _order) < 0 && lower < higher)
				lower++;
	
			//앞과 뒤가 만나지 않았다면
			if(higher != lower)
			{
				//값을 교체한다.
				_data[higher] = _data[lower];
				higher--;
			}
		}

		//피벗을 기준으로한 정렬이 끝나고 빈곳에 피벗값을 넣는다.
		_data[lower] = pivot;
	
		//피벗의 왼쪽값을 재정렬한다.
		QSort(_data, _order, _first, lower - _first);
		//피벗의 오른쪽값을 재정렬한다.
		QSort(_data, _order, lower + 1, last - lower);
	}	
}
	
}

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

	if(compare(_array[mid], _array[_first]) < 0 && 
		compare(_array[mid], _array[last]) < 0)
	{
		if(compare(_array[_first], _array[last]) < 0)
			return _first;
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