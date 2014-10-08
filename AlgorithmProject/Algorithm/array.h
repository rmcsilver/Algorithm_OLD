/*----------------------------------------------------------------
이름 : 배열 클래스
작업자 : 조이현
설명 : 배열을 템플릿 클래스로 정의
만든날짜 : 2013.12.21
화일명 : array.h
----------------------------------------------------------------*/
#pragma once

#include <stdio.h>
#include <cassert>

template<class T>
class Array
{
private:
	T* data;
	int size;

public:
	
/*----------------------------------------------------------------
이름: Array::Array
설명: 생성자. 사이즈를 입력받아서 생성한다.
----------------------------------------------------------------*/
	Array(int _size)
	{
		data = new T[_size];
		ZeroMemory(data, sizeof(T) * _size);
		size =  _size;
	}

/*----------------------------------------------------------------
이름: Array::~Array
설명: 기본 소멸자. 
----------------------------------------------------------------*/
	~Array()
	{
		if(data != 0)	delete [] data;
		data = 0;
	}

/*----------------------------------------------------------------
이름: Array::operator[]
설명: 기본배열과 같이 접근하기 위해 연산자오버로딩 
리턴값:	해당 인덱스의 배열값
----------------------------------------------------------------*/
	T& operator[](int _index)
	{
		assert(_index < size && "입력값이 사이즈를 초과했습니다.");
		return data[_index];
	}

/*----------------------------------------------------------------
이름: Array::Size
설명: 배열 데이터의 사이즈를 알아낸다.
리턴값: 배열 데이터의 사이즈
----------------------------------------------------------------*/
	int Size()
	{
		return size;
	}

/*----------------------------------------------------------------
이름: Array::Resize
설명: 현재의 배열사이즈를 변경한다.
----------------------------------------------------------------*/
	void Resize(int _size)
	{
		T* NewArray = new T[_size];
		ZeroMemory(NewArray, sizeof(T) * _size);

		if(NewArray == 0)	return;

		int count = size;
		if(_size < size)	count = _size;

		for(int i = 0; i < count; i++)
			NewArray[i] = data[i];

		size = _size;

		if(data != 0)	delete [] data;

		data = NewArray;
	}

/*----------------------------------------------------------------
이름: Array::Insert
설명: 해당위치에 배열의 값을 넣는다.
인자값: _value : 넣으려는 값
		_index : 넣으려는 위치
----------------------------------------------------------------*/
	void Insert(T _value, int _index)
	{
		int index;
		//인덱스가 이미 입력된 값들의 중간에 있다면 값을 이동시킨다.
		for(index = size - 1; index > _index; index--)
			data[index] = data[index-1];

		data[_index] = _value;
	}

/*----------------------------------------------------------------
이름: Array::Remove
설명: 해당 위치의 값을 없앤다.
인자값: _index : 지우려는 값의 위치
----------------------------------------------------------------*/
	bool Remove(int _index)
	{
		if(_index > size)	return false;

		int index;
		//인덱스가 중간에 있다면 해당위치 이후의 값을 이동시킨다.
		for(index = _index + 1; index < size; index++)
			data[index - 1] = data[index];

		return true;
	}

/*----------------------------------------------------------------
이름: Array::operator T*
설명: 함수의 인수로 배열을 사용하기 위한 형변환
----------------------------------------------------------------*/
	operator T*()
	{
		return data;
	}

/*----------------------------------------------------------------
이름: Array::WriteFile
설명: 
----------------------------------------------------------------*/
	bool WriteFile(const char* _filename)
	{
		FILE* outFile = 0;
		int written = 0;

		outFile = fopen(_filename, "wb");
		if(outFile == 0)	return false;

		written = fwrite(data, sizeof(T), size, outFile);

		fclose(outFile);

		if(written != size)
			return false;

		return true;
	}

/*----------------------------------------------------------------
이름: Array::ReadFile
설명: 
----------------------------------------------------------------*/
	bool ReadFile(const char* _filename)
	{
		FILE* inFile = 0;
		int read = 0;

		inFile = fopen(_filename, "rb");

		if(inFile == 0)	return false;

		read = fread(data, sizeof(T), size, inFile);
		fclose(inFile);

		if(read != size)	return false;

		return true;
	}
};

template <class T>
class Array2D
{
private:
	T* data;
	int width;
	int height;

public:
	Array2D():data(NULL), width(0), height(0){}
	~Array2D()
	{
		if(data != 0)	delete [] data;
		data = 0;
	}
	Array2D(int _width, int _height);

	T& Get()
	{

	}

	void Resize(int _width, int _height);
	int Size();
	int Width();
	int Height();

};

class Array3D
{
private:

public:
};

