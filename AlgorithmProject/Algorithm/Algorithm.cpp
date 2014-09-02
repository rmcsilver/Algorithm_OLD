#include <Windows.h>
#include <iostream>
#include "Algorithm.h"

namespace Algorithm
{
	int Run()
	{
		int UseType = 1;

		while(UseType != 0)
		{
			std::cout<<"�׽�Ʈ�� �ڷ����� �����ϼ���."<<std::endl;
			std::cout<<"1 -> �迭(array)"<<std::endl;
			std::cout<<"0 -> ����"<<std::endl;
			std::cin>>UseType;

			if(UseType == 0)
			{
				return -1;
			}

			switch( static_cast<EDATA_TYPE>(UseType) )
			{
			case eArray:
				{
					std::cout<<"\n1.�迭����"<<std::endl;
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
					std::cout<<"\n�߸��� �Է��Դϴ�.\n"<<std::endl;
				}break;
			}
		}

		return 1;
	}
}
