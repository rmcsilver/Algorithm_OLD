template<class T>
class Array
{
private:
	T* data;
	int size;
public:
	Array(int _size)
	{
		data = new T[_size];
		ZeroMemory(data, sizeof(T) * _size);
		size =  _size;
	}
	~Array()
	{
		if(data != 0)	delete [] data;
		data = 0;
	}

	T& operator[](int index)
	{
		return data[index];
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
			NewArray[i] = data[i];

		size = _size;

		if(data != 0)	delete [] data;

		data = NewArray;
	}

	void Insert(T Item, int index)
	{
		for(int i = size - 1; i > size; i--)
			data[i] = data[i-1];

		data[index] = Item;
	}

	void Remove(int index)
	{
		for(int i=index + 1; i < size; i++)
			data[i - 1] = data[i];
	}

	operator T*()
	{
		return data;
	}

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

