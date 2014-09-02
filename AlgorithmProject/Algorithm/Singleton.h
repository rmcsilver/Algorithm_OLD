////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*

Begin Date : 2014.07.07
Title : �̱��� �ۺ� Ŭ����
FeedBack : taijiofx@gmail.com
���� : �̱����� ����ϱ� ���� �ۺ����� ������� Ŭ������ ����Ѵ�.

*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _Singleton_
#define _Singleton_

#include <iostream>
#include <assert.h>

template <class T>
class Singleton
{
public:
	static T* GetSingleton() 
	{
		if (!m_pInstance)
		{
			m_bInitialized = true;
			m_pInstance = new T;
		}
			assert(m_pInstance != NULL);
			return m_pInstance;
	}

	static void DestroySingleton() 
	{
		if (m_pInstance) 
		{
			delete m_pInstance;
			m_pInstance = NULL;
		}
	}

static bool m_bInitialized;

protected:
		Singleton() {
				assert(!m_pInstance);
				assert(m_bInitialized);
		};
private:
		static T* m_pInstance;
		Singleton(Singleton const&);            // ���� ����
		Singleton& operator=(Singleton const&); // �Ҵ� ����
};

template <class T> T* Singleton<T>::m_pInstance = NULL;
template <class T> bool Singleton<T>::m_bInitialized = false;

#endif