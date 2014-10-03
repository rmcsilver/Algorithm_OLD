class Bitvector
{
private:
	unsigned long int* data;
	int size;
public:
	Bitvector();
	Bitvector(int _size)
	{
		data = 0;
		size = 0;
		Resize(_size);
	}
	~Bitvector()
	{
		if(data != 0)
			delete [] data;
		data = 0;
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
			vector[i] = data[i];
			
		size = _size;

		if(data != 0)	delete [] data;

		data = vector;
	}

	bool operator[](int _index)
	{
		int cell = _index / 32;
		int bit = _index % 32;
		bool result = true;
		if( (data[cell] & (1 << bit)) >> bit == 0)	result = false;
		return result;
	}

	void Set(int _index, bool _value)
	{
		int cell = _index / 32;
		int bit = _index % 32;

		if(_value == true)
			data[cell] = (data[cell] | (1 << bit));
		else
			data[cell] = (data[cell] & (~(1 << bit)));
	}

	void ClearAll()
	{
		for(int i = 0; i < size; i++)
			data[i] = 0;
	}

	void SetAll()
	{
		for(int i = 0; i < size; i++)
			data[i] = 0xFFFFFFFF;
	}

	int Size()
	{
		return size;
	}

	bool WriteFile(const char* _filename)
	{
		FILE* outFile = 0;
		int written = 0;

		int result = fopen_s(&outFile, _filename, "wb");
		if(result == 0)	return false;

		written = fwrite(data, sizeof(unsigned long int), size, outFile);

		fclose(outFile);

		if(written != size)
			return false;

		return true;
	}

	bool ReadFile(const char* _filename)
	{
		FILE* inFile = 0;
		int read = 0;

		int result = fopen_s(&inFile, _filename, "rb");

		if(result == 0)	return false;

		read = fread(data, sizeof(unsigned long int), size, inFile);
		fclose(inFile);

		if(read != size)	return false;

		return true;
	}
};
