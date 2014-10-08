/*----------------------------------------------------------------
�̸� : ���� ���̺귯��
�۾��� : ������
���� : ���İ��� �Լ����� ����
���糯¥ : 2013.12.21
ȭ�ϸ� : sort.h
----------------------------------------------------------------*/
#pragma once

#include <vector>

//����Ÿ��
namespace SortOrder
{
	enum Type
	{
		Ascending_Order = 0,	//��������Ÿ��
		Descending_Order,		//��������Ÿ��
	};
}

namespace SortLib
{
 
/*----------------------------------------------------------------
�̸�: Compare
����: �Է¹��� �� ���� ���ϴ� ���ø� �Լ�
���ڰ�: _value1, _value2 : ���Ϸ��� �� ��.
		_order : ���Ϸ��� ���(��������, �������� ����)
���ϰ�:	�� ���� ���� ������ ������ 1, �ٸ��ٸ� -1, ���ٸ� 0
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
�̸�: FindMedian
����: ���� ��ü �����Ϳ��� ó��,�߰�,�������� ���� �߿� �߰����� ã�� ���ø� �Լ�
���ڰ�: _data : ���� ��ü ������
		_first : ������ġ
		_size : ������
		_order : ���Ĺ��
���ϰ�:	�߰������� ���õ� ���� ��ġ
----------------------------------------------------------------*/
template<class T>
int FindMedian(std::vector<T>& _data, int _first, int _size, SortOrder::Type _order)
{
	int _last = _first + _size - 1;
	int _mid = _first + (_size / 2);

	T first = _data.at(_first);
	T mid = _data.at(_mid);
	T last = _data.at(_last);

	//1.ù��°������ �߰���, ���������� ũ�ٸ�,
	if( (Compare(first, mid, _order) > 0) && (Compare(first, last, _order) > 0))
	{
		//�߰����� �������� �߿� ���� ���� �����Ѵ�.
		if(Compare(mid, last, _order) > 0)	return _mid;
		else return _last;
	}

	//2.�߰������� ù��°��, ���������� ũ�ٸ�,
	if( (Compare(mid, first, _order) > 0) && (Compare(mid, last, _order) > 0))
	{
		//ù��°���� �������� �߿� ���� ���� �����Ѵ�.
		if(Compare(first, last, _order) > 0)	return _first;
		else return _last;
	}

	//3.������������ ù��°��, �߰����� ũ�ٸ�, ù��°���� �߰��� �߿� ���� ���� �����Ѵ�.
	if(Compare(first, mid, _order) > 0)	return _first;
	else return _mid;
}

/*----------------------------------------------------------------
�̸�: QSort
����: ���� ��ü �����͸� ����Ʈ�ϴ� ���ø� �Լ�.
		����Լ��̸� FindMedian()�Լ��� ����Ͽ� �־��� ���Ľð��� �����Ѵ�.
���ڰ�: _data : ���� ��ü ������
		_order : ���Ĺ��
		_first : ������ġ
		_size : ������
���ϰ�:	�߰������� ���õ� ���� ��ġ
----------------------------------------------------------------*/
template<class T>
void QSort(std::vector<T>& _data, SortOrder::Type _order = SortOrder::Ascending_Order, int _first = -1, int _size = -1)
{
	//����Ʈ �μ����� ���� ��ü�� ������ �Ѵ�.
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
		//�ǹ��� �� �߰����� ã�´�.
		mid = FindMedian(_data, _first, _size, _order);
		pivot = _data[mid];

		//ù��° �ڸ��� ���� ���� ���õ� ���ڸ��� ù��° ���� �Է��Ѵ�.
		_data[mid] = _data[_first];

		while(lower < higher)
		{
			//�ڿ������� ������ �ǹ����� ���Ĺ���� �´¼��� �ִ��� �˻��Ѵ�.
			while(Compare(pivot, _data[higher], _order) > 0 && lower < higher)
				higher--;

			//�հ� �ڰ� ������ �ʾҴٸ� 
			if(higher != lower)
			{
				//���� ��ü�Ѵ�.
				_data[lower] = _data[higher];
				lower++;
			}
			
			//�տ������� �ڱ��� �ǹ����� ���Ĺ���� �ݴ�Ǵ� ���� �ִ��� �˻��Ѵ�.
			while(Compare(pivot, _data[lower], _order) < 0 && lower < higher)
				lower++;
	
			//�հ� �ڰ� ������ �ʾҴٸ�
			if(higher != lower)
			{
				//���� ��ü�Ѵ�.
				_data[higher] = _data[lower];
				higher--;
			}
		}

		//�ǹ��� ���������� ������ ������ ����� �ǹ����� �ִ´�.
		_data[lower] = pivot;
	
		//�ǹ��� ���ʰ��� �������Ѵ�.
		QSort(_data, _order, _first, lower - _first);
		//�ǹ��� �����ʰ��� �������Ѵ�.
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