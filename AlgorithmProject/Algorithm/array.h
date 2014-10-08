/*----------------------------------------------------------------
�̸� : �迭 Ŭ����
�۾��� : ������
���� : �迭�� ���ø� Ŭ������ ����
���糯¥ : 2013.12.21
ȭ�ϸ� : array.h
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
�̸�: Array::Array
����: ������. ����� �Է¹޾Ƽ� �����Ѵ�.
----------------------------------------------------------------*/
	Array(int _size)
	{
		data = new T[_size];
		ZeroMemory(data, sizeof(T) * _size);
		size =  _size;
	}

/*----------------------------------------------------------------
�̸�: Array::~Array
����: �⺻ �Ҹ���. 
----------------------------------------------------------------*/
	~Array()
	{
		if(data != 0)	delete [] data;
		data = 0;
	}

/*----------------------------------------------------------------
�̸�: Array::operator[]
����: �⺻�迭�� ���� �����ϱ� ���� �����ڿ����ε� 
���ϰ�:	�ش� �ε����� �迭��
----------------------------------------------------------------*/
	T& operator[](int _index)
	{
		assert(_index < size && "�Է°��� ����� �ʰ��߽��ϴ�.");
		return data[_index];
	}

/*----------------------------------------------------------------
�̸�: Array::Size
����: �迭 �������� ����� �˾Ƴ���.
���ϰ�: �迭 �������� ������
----------------------------------------------------------------*/
	int Size()
	{
		return size;
	}

/*----------------------------------------------------------------
�̸�: Array::Resize
����: ������ �迭����� �����Ѵ�.
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
�̸�: Array::Insert
����: �ش���ġ�� �迭�� ���� �ִ´�.
���ڰ�: _value : �������� ��
		_index : �������� ��ġ
----------------------------------------------------------------*/
	void Insert(T _value, int _index)
	{
		int index;
		//�ε����� �̹� �Էµ� ������ �߰��� �ִٸ� ���� �̵���Ų��.
		for(index = size - 1; index > _index; index--)
			data[index] = data[index-1];

		data[_index] = _value;
	}

/*----------------------------------------------------------------
�̸�: Array::Remove
����: �ش� ��ġ�� ���� ���ش�.
���ڰ�: _index : ������� ���� ��ġ
----------------------------------------------------------------*/
	bool Remove(int _index)
	{
		if(_index > size)	return false;

		int index;
		//�ε����� �߰��� �ִٸ� �ش���ġ ������ ���� �̵���Ų��.
		for(index = _index + 1; index < size; index++)
			data[index - 1] = data[index];

		return true;
	}

/*----------------------------------------------------------------
�̸�: Array::operator T*
����: �Լ��� �μ��� �迭�� ����ϱ� ���� ����ȯ
----------------------------------------------------------------*/
	operator T*()
	{
		return data;
	}

/*----------------------------------------------------------------
�̸�: Array::WriteFile
����: 
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
�̸�: Array::ReadFile
����: 
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

