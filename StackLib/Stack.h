#pragma once

using namespace std;

const int MaxMemSize = 25;

template <class T>
class TStack
{
public:
	TStack(int _size = 1);
	TStack(const TStack<T>& _copy);
	TStack(T* _arr, size_t _sz);
	~TStack();

	void Push(const T& _elem);
	T Pop();
	T Top();

	bool IsEmpty() const;
	bool IsFull() const;

	int GetSize();
	int GetStart();

	TStack<T> operator=(const TStack<T>& _stack);

protected:
	T* pMem;
	int size;
	int start;
	int elemCount;
};

template<class T>
inline TStack<T>::TStack(int _size)
{
	if (_size >= 1 && _size <= MaxMemSize)
	{
		size = _size;

		pMem = new T[size];

		start = 0;

		elemCount = 0;

		for (int i = 0; i < size; i++)
		{
			pMem[i] = 0;
		}
	}
	else
	{
		throw "size error";
	}
}

template<class T>
inline TStack<T>::TStack(const TStack<T>& _stack)
{
	if (_stack.pMem == nullptr)
		throw "data error";
	else
	{
		size = _stack.size;

		start = _stack.start;

		elemCount = _stack.elemCount;
		
		pMem = new T[size];

		for (int i = 0; i < size; i++)
		{
			pMem[i] = _stack.pMem[i];
		}
	}
}

template<class T>
inline TStack<T>::TStack(T* _arr, size_t _sz)
{
	if (_sz < 1 && _sz > MaxMemSize)
		throw "size error";
	if (_arr == nullptr)
		throw "data error";
	else
	{
		size = _sz;

		start = 0;

		elemCount = size;

		pMem = new T[size];

		for (int i = 0; i < size; i++)
		{
			pMem[i] = _arr[i];
		}

	}
}

template<class T>
inline TStack<T>::~TStack()
{
	if (pMem != nullptr)
		delete[] pMem;
}

template<class T>
inline void TStack<T>::Push(const T& _elem)
{
	if (this->IsFull() != true)
	{
		pMem[start] = _elem;

		start++;
	}
	else
	{
		TStack<T> res(pMem, size * 2);

		res.pMem[start] = _elem;

		res.start++;

		*this = res;
	}
}

template<class T>
inline T TStack<T>::Pop()
{
	if (IsEmpty() != true)
	{
		pMem[start - 1] = 0;

		start--;
	}
	else
	{
		throw "IsEmpty error";
	}
}

template<class T>
inline T TStack<T>::Top()
{
	if (IsEmpty() != true)
	{
		return pMem[start - 1];
	}
	else
	{
		throw "IsEmpty error";
	}
}

template<class T>
inline bool TStack<T>::IsEmpty() const
{
	return (elemCount == 0);
}

template<class T>
inline bool TStack<T>::IsFull() const
{
	return (elemCount == size);
}

template<class T>
inline int TStack<T>::GetSize()
{
	return size;
}

template<class T>
inline int TStack<T>::GetStart()
{
	return start;
}

template<class T>
inline TStack<T> TStack<T>::operator=(const TStack<T>& _stack)
{
	if (_stack.pMem == nullptr)
		throw "data error";
	else
	{
		if (pMem != nullptr)
			delete[] pMem;

		size = _stack.size;

		start = _stack.start;

		elemCount = _stack.elemCount;

		pMem = new T[size];

		for (int i = 0; i < size; i++)
		{
			pMem[i] = _stack.pMem[i];
		}
	}
}
