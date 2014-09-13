#pragma once

namespace Algorithm
{
	enum EDATA_TYPE
	{
		eArray = 1,
		eBitvector,
		eMax
	};

	class Bitvector
	{
	private:
		unsigned long int* arrayData;
		int size;
	public:
		Bitvector();
		Bitvector(int _size)
		{
			arrayData = 0;
			size = 0;
			Resize(_size);
		}
		~Bitvector()
		{
			if(arrayData != 0)
				delete [] arrayData;
			arrayData = 0;
		}

		void Resize(int _size)
		{
			unsigned long int* vector = 0;
			if(_size % 32 ==0)
				_size = _size / 32;
			else
				_size = (_size/32) + 1;

			vector = new unsigned long int[_size];

			if(vector == 0)	return;

			int count = size;
			if(_size < size) count = _size;

			for(int i= 0; i < count; i++)
				vector[i] = arrayData[i];
			
			size = _size;

			if(arrayData != 0)	delete [] arrayData;

			arrayData = vector;
		}

		bool operator[](int _index)
		{
			int cell = _index / 32;
			int bit = _index % 32;
			return (arrayData[cell] & (1 << bit)) >> bit;
		}

		void Set(int _index, bool _value)
		{
			int cell = _index / 32;
			int bit = _index % 32;

			if(_value == true)
				arrayData[cell] = (arrayData[cell] | (1 << bit));
			else
				arrayData[cell] = (arrayData[cell] & (~(1 << bit)));
		}

		void ClearAll()
		{
			for(int i = 0; i < size; i++)
				arrayData[i] = 0;
		}

		void SetAll()
		{
			for(int i = 0; i < size; i++)
				arrayData[i] = 0xFFFFFFFF;
		}

		int Size()
		{
			return size;
		}

		bool WriteFile(const char* _filename)
		{
			FILE* outFile = 0;
			int written = 0;

			outFile = fopen(_filename, "wb");
			if(outFile == 0)	return false;

			written = fwrite(arrayData, sizeof(unsigned long int), size, outFile);

			fclose(outFile);

			if(written != size)
				return false;

			return true;
		}

		bool ReadFile(const char* _filename)
		{
			FILE* inFile = 0;
			int read = 0;

			inFile = fopen(_filename, "rb");

			if(inFile == 0)	return false;

			read = fread(arrayData, sizeof(unsigned long int), size, inFile);
			fclose(inFile);

			if(read != size)	return false;

			return true;
		}
	};

	template<class T>
	class Array
	{
	private:
		T* arrayData;
		int size;
	public:
		Array(int _size)
		{
			arrayData = new T[_size];
			ZeroMemory(arrayData, sizeof(T) * _size);
			size =  _size;
		}
		~Array()
		{
			if(arrayData != 0)	delete [] arrayData;
			arrayData = 0;
		}

		T& operator[](int index)
		{
			return arrayData[index];
		}

		int Size()
		{
			return size;
		}

		void Resize(int _size)
		{
			T* NewArray = new T[_size];
			ZeroMemory(NewArray, sizeof(T) * _size);

			if(NewArray == 0)	return;

			int count = size;
			if(_size < size)	count = _size;

			for(int i = 0; i < count; i++)
				NewArray[i] = arrayData[i];

			size = _size;

			if(arrayData != 0)	delete [] arrayData;

			arrayData = NewArray;
		}

		void Insert(T Item, int index)
		{
			for(int i = size - 1; i > size; i--)
				arrayData[i] = arrayData[i-1];

			arrayData[index] = Item;
		}

		void Remove(int index)
		{
			for(int i=index + 1; i < size; i++)
				arrayData[i - 1] = arrayData[i];
		}

		operator T*()
		{
			return arrayData;
		}

		bool WriteFile(const char* _filename)
		{
			FILE* outFile = 0;
			int written = 0;

			outFile = fopen(_filename, "wb");
			if(outFile == 0)	return false;

			written = fwrite(arrayData, sizeof(T), size, outFile);

			fclose(outFile);

			if(written != size)
				return false;

			return true;
		}

		bool ReadFile(const char* _filename)
		{
			FILE* inFile = 0;
			int read = 0;

			inFile = fopen(_filename, "rb");

			if(inFile == 0)	return false;

			read = fread(arrayData, sizeof(T), size, inFile);
			fclose(inFile);

			if(read != size)	return false;

			return true;
		}
	};

	int Run();
}