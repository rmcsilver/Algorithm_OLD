////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*

Begin Date : 2014.07.07
Title : 싱글턴 템블릿 클래스
FeedBack : taijiofx@gmail.com
설명 : 싱글턴을 사용하기 위해 템블릿으로 만들어진 클래스를 사용한다.

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
		Singleton(Singleton const&);            // 복사 숨김
		Singleton& operator=(Singleton const&); // 할당 숨김
};

template <class T> T* Singleton<T>::m_pInstance = NULL;
template <class T> bool Singleton<T>::m_bInitialized = false;

#endif