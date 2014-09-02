#include <stdio.h>
#include <iostream>
#include <Windows.h>

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

void main()
{
	int UseType = 1;

	while(UseType != 0)
	{
		std::cout<<"테스트할 자료형을 선택하세요."<<std::endl;
		std::cout<<"1 -> 배열(array)"<<std::endl;
		std::cout<<"0 -> 종료"<<std::endl;
		std::cin>>UseType;

		if(UseType == 0)
		{
			return;
		}

		switch( static_cast<EDATA_TYPE>(UseType) )
		{
		case eArray:
			{
				std::cout<<"\n1.배열선택"<<std::endl;
				Array<int> intarray( 10 );
				Array<float> floatarray( 5 );
				
				intarray[0] = 10;
				int iData = intarray[0];
			    intarray[1] = 12;
				intarray.Insert( 11, 1 );
			    intarray.Remove( 0 );
				intarray.Resize( 3 );
			    
				floatarray[0] = 3.1415f;
				float fData = floatarray[0];
				floatarray[1] = 6.28f;
				floatarray.Insert( 4.2f, 1 );
				floatarray.Remove( 0 );
				floatarray.Resize( 4 );

				int i = 0;
				for(i = 0; i < intarray.Size(); i++)
					std::cout<<intarray[i]<<std::endl;

				std::cout<<"\n"<<std::endl;

				for(i = 0; i < floatarray.Size(); i++)
					std::cout<<floatarray[i]<<std::endl;

				std::cout<<"\n"<<std::endl;
			}
			break;
		default:
			{
				std::cout<<"\n잘못된 입력입니다.\n"<<std::endl;
			}break;
		}
	}
}