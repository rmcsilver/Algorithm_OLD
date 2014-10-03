#include "Algorithm.h"

namespace Algorithm
{
	// compare integers
	int compareint( int l, int r )
	{
		return l - r;
	}


	// compare the integers in reverse order
	int compareintreverse( int l, int r )
	{
		return r - l;
	}


	// compare floats
	int comparefloat( float l, float r )
	{
		if( l < r )
			return -1;
		if( l > r )
			return 1;
		return 0;
	}

	int Run()
	{
		int UseType = 1;

		while(UseType != 0)
		{
			std::cout<<"테스트할 자료형을 선택하세요."<<std::endl;
			std::cout<<"1 -> 배열(array)"<<std::endl;
			std::cout<<"2 -> 비트벡터(bitvector)"<<std::endl;
			std::cout<<"3 -> 퀵소트(quicksort)"<<std::endl;
			std::cout<<"0 -> 종료"<<std::endl;
			std::cin>>UseType;

			if(UseType == 0)
			{
				return -1;
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
				}break;

			case eBitvector:
				{
					std::cout<<"\n2.비트백터선택"<<std::endl;
					Bitvector bitv(32);
					
					bool b;
					
					bitv.ClearAll();
					bitv.SetAll();

					bitv.Set(0, false);
					b = bitv[0];
					std::cout<<"0번째 비트 0으로 셋팅 후 -> "<<b<<std::endl;

					bitv.Set(31, false);
					b = bitv[31];
					std::cout<<"31번째 비트 0으로 셋팅 후 -> "<<b<<std::endl;

					bitv.Set(0, true);
					b = bitv[0];
					std::cout<<"0번째 비트 1로 셋팅 후 -> "<<b<<std::endl;

		//			bitv.Resize(48);

					int size = bitv.Size();

					for(int i = 0; i < 32; i++)
					{
						std::cout<<bitv[i]<<std::endl;
					}
					std::cout<<"\n"<<std::endl;
				}break;

			case eQuickSort:
				{
					Array<int> iarray( 16 );
					Array<float> farray( 16 );

					int index;

					// seed the randomizer, see Chapter 22.
					srand( time(0) );

					// fill up the arrays with random values
					for( index = 0; index < 16; index++ )
					{
						// 0-255
						iarray[index] = rand() % 256;

						// 0-1
						farray[index] = (float)(rand() % 256) / 256.0f;
					}


					QuickSort( iarray, 0, 16, compareint );
					QuickSort( farray, 0, 16, comparefloat );

					std::cout << "Integer Array: ";
					PrintArray( iarray );
					std::cout << std::endl;

					std::cout << "Float Array: ";
					PrintArray( farray );
					std::cout << std::endl;


					// reverse the integer array
					QuickSort( iarray, 0, 16, compareintreverse );

					std::cout << "Integer Array Reversed: ";
					PrintArray( iarray );
					std::cout << std::endl;

				}break;

			default:
				{
					std::cout<<"\n잘못된 입력입니다.\n"<<std::endl;
				}break;
			}
		}

		return 1;
	}
}
