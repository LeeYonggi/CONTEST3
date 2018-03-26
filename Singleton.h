#pragma once


template<class T>
class Singleton
{
private:
	static T *p;
public:
	static T *GetSingleton()
	{
		if (!p)
			p = new T;
		return p;
	}
	static void ReleaseSingleton()
	{
		SAFE_DELETE(p);
	}
};

template<typename T>
T *Singleton<T>::p = nullptr;