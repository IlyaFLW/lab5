#ifndef STECK_H
#define STECK_H

#include <iostream>
#include <fstream>

using namespace std;

template <typename T>
class TSteck
{
private:
	T* steckPtr;                      
	const int size;                  
	int num;                          
public:
	TSteck(int = 10);                 
	TSteck(const TSteck<T>&);          
	~TSteck();                         

	inline void push(const T&);    
	inline T del();                   
	inline const T& Peek(int) const; 
	inline int getSteckSize() const; 
	inline T* getPtr() const;         
	inline int getNum() const;        

	
	inline int min_elem(); 
	inline int max_elem(); 
	inline void file(); 

	friend ostream& operator<<(ostream& out, const TSteck& st)
	{
		for (int ix = st.num - 1; ix >= 0; ix--)
			cout << st.steckPtr[ix] << endl;
		return out;
	}
};


template <typename T>
TSteck<T>::TSteck(int maxSize) : size(maxSize) 
{
	if (maxSize < 0)
	{
		throw "Error";
	}
	steckPtr = new T[size]; 
	num = 0; 
}


template <typename T>
TSteck<T>::TSteck(const TSteck<T>& otherSteck) : size(otherSteck.getSteckSize()) 
{
	steckPtr = new T[size];
	num = otherSteck.getNum();

	for (int ix = 0; ix < num; ix++)
	{
		steckPtr[ix] = otherSteck.getPtr()[ix];
	}
}

template <typename T>
TSteck<T>::~TSteck()
{
	if (this->steckPtr != NULL)
	{
		delete[] steckPtr;
	}
	num = 0;
}


template <typename T>
inline void TSteck<T>::push(const T& value)
{
	if (num > size - 1 || num < 0)
	{
		throw "Error";
	}

	steckPtr[num++] = value;
}


template <typename T>
inline T TSteck<T>::del()
{
	if (num < 0)
	{
		throw "Error";
	}

	steckPtr[--num]; 

	return steckPtr[num];
}


template <class T>
inline const T& TSteck<T>::Peek(int Elem) const
{
	if (Elem > num)
	{
		throw "Error";
	}
	return steckPtr[num - Elem];
}

template <typename T>
inline int TSteck<T>::getSteckSize() const
{
	return size;
}


template <typename T>
inline T* TSteck<T>::getPtr() const
{
	return steckPtr;
}


template <typename T>
inline int TSteck<T>::getNum() const
{
	return num;
}

template<typename T>
inline int TSteck<T>::max_elem()
{
	int res = steckPtr[0];
	for (int i = 1; i < size; i++)
	{
		if (steckPtr[i] > res)
		{
			res = steckPtr[i];
		}
	}
	return res;
}

template<typename T>
inline int TSteck<T>::min_elem()
{
	int res = steckPtr[0];
	for (int i = 1; i < size; i++)
	{
		if (steckPtr[i] < res)
		{
			res = steckPtr[i];
		}
	}
	return res;
}

template<typename T>
inline void TSteck<T>::file()
{
	ofstream outf("Data.txt");
	if (!outf)
	{
		throw "Error file";
	}
	for (int i = 0; i < size; i++)
	{
		outf << steckPtr[i] << endl;
	}
}
#endif 