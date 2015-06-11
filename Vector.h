#pragma once

#include<stdexcept>


template<typename T>
class Vector
{
public:
	Vector();
	Vector(int capacity);
	Vector(const Vector& v);

	Vector& operator=(const Vector& v);
	~Vector();

	void push_back(const T& x);
	void pop_back();
	T& back();
	T& front();
	void insert(int index, T value);
	void erase(int index);
	T& operator[](int index);
	int size();
	int capacity();
	bool empty();
	void clear();
	
	class iterator
	{
	public:
		iterator() {}
		iterator(Vector& v, int index)
		{
			m_index = index;
			m_vsize = v.size();
			if (m_index == m_vsize)
			{
				m_p = (v.m_arr + index);
			}
			else
			{
				m_p = &v[index];
			}
		}
		iterator(const iterator& it)
		{
			m_index = it.m_index;
			m_p = it.m_p;
			m_vsize = it.m_vsize;
		}
		iterator operator=(const iterator& it)
		{
			m_index = it.m_index;
			m_p = it.m_p;
			m_vsize = it.m_vsize;
			return *this;
		}

		T& operator*()
		{
			return *m_p;
		}

		iterator& operator++()
		{
			if (m_vsize > m_index)
			{
				m_index++;
				m_p++;
				return *this;
			}
			else
			{
				throw std::out_of_range("izlizate izvan vektora");
			}
		}
		iterator& operator--()
		{
			if (m_index > 0)
			{
				m_index--;
				m_p--;
				return *this;
			}
			else
				throw std::out_of_range("izlizate izvan vektora");
		}

		iterator operator+(const int& value) const
		{
			if (m_index + value-1 < m_vsize)
			{
				iterator it(*this);
				it.m_index += value;
				it.m_p += value;
				return it;
			}
			else
				throw std::out_of_range("izlizate izvan vektora");
		}
		iterator operator-(const int& value) const
		{
			if (m_index - value > 0)
			{
				iterator it(*this);
				it.m_index -= value;
				it.m_p -= value;
				return it;
			}
			else
				throw std::out_of_range("izlizate izvan vektora");
		}


		bool operator!=(const iterator& it)
		{
			return m_index != it.m_index;
		}

	private:
		T* m_p;
		int m_index;
		int m_vsize;
	};

	iterator begin()
	{
		iterator it(*this, 0);
		return it;
	}

	iterator end()
	{
		iterator it(*this, m_size);
		return it;
	}

	void assign(int, T);
	void assign(T*, T*);
	void assign(iterator, iterator);
private:
	int m_size;
	int m_capacity;
	T*	m_arr;

	void changeCapacity(int newCapacity);
};






template<typename T>
Vector<T>::Vector()
{
	m_size = 0;
	m_capacity = 1;
	m_arr = new T[m_capacity];
}
template<typename T>
Vector<T>::Vector(int capacity)
{
	if (capacity < 1)
		throw std::length_error("vaveli ste nevalidno 4islo za mqrka");
	else
	{
		m_size = 0;
		m_capacity = capacity;
		m_arr = new T[m_capacity];
	}
}
template<typename T>
Vector<T>::Vector(const Vector& v)
{
	m_size = v.m_size;
	m_capacity = v.m_capacity;
	m_arr = new T[m_capacity];
	for (int i = 0; i < size; i++)
		m_arr[i] = v.m_arr[i];
}


template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& v)
{
	m_size = v.m_size;
	m_capacity = v.m_capacity;
	m_arr = new T[m_capacity];
	for (int i = 0; i < size; i++)
		m_arr[i] = v.m_arr[i];
}


template<typename T>
Vector<T>::~Vector()
{
	delete[] m_arr;
}


template<typename T>
void Vector<T>::push_back(const T& x)
{
	if (m_size == m_capacity)
	{
		changeCapacity(m_capacity * 2);
	}
	m_arr[m_size] = x;
	m_size++;
}


template<typename T>
void Vector<T>::pop_back()
{
	if (m_size > 0)
	{

		m_size--;
		if ((((double)(m_size + 1) / m_capacity)) < 0.25)
		{
			changeCapacity(m_capacity / 2);
		}
	}
	else
		throw std::out_of_range("nama pove4e elementi");
}


template<typename T>
void Vector<T>::changeCapacity(int newCapasity)
{
	T* arr1;
	m_capacity = newCapasity;
	arr1 = new  T[m_capacity];
	for (int i = 0; i < m_size; i++)
	{
		arr1[i] = m_arr[i];
	}
	delete[] m_arr;
	m_arr = arr1;
}


template<typename T>
T& Vector<T>::back()
{
	if (m_size > 0)
	{
		return m_arr[m_size - 1];
	}
	else
		throw std::out_of_range("nqma pove4e elementi>");
}

template<typename T>
T& Vector<T>::front()
{
	if (m_size > 0)
	{
		return m_arr[0];
	}
	else
		throw std::out_of_range("vektora e prazen");
}

//--------------------------------------------//
template<typename T>
void Vector<T>::insert(int index, T value)
{
	if (m_size == m_capacity)
		changeCapacity(m_capacity * 2);
	T* arr1;
	arr1 = new  T[m_capacity];
	for (int i = 0; i < m_size; i++)
	{
		arr1[i] = m_arr[i];
	}
	arr1[m_size] = value;
	delete[] m_arr;
	m_arr = arr1;
	m_size++;
	for (auto it = this->end() - 1; it != this->begin() + index ; it--)
	{
		swap(*it, *(it - 1));
	}
}
//-----------------------------------------------//
template<typename T>
void Vector<T>::erase(int index)
{
	if (m_size >index&& index>=0)
	{
		for (auto it = this->begin() + index; it != this->end()-1; it++)
		{
			swap(*it, *(it + 1));
		}
		m_size--;
		if ((((double)(m_size + 1) / m_capacity)) < 0.25)
		{
			changeCapacity(m_capacity / 2);
		}
		T* arr1;
		arr1 = new  T[m_capacity];
		for (int i = 0; i < m_size; i++)
		{
			arr1[i] = m_arr[i];
		}
		delete[] m_arr;
		m_arr = arr1;
	}
	else
		throw std::out_of_range("opitvate se da dostignete nesa6testvuva6t element");
}

template<typename T>
T& Vector<T>:: operator[](int index)
{
	if (index < m_size && index >= 0)
		return m_arr[index];
	else
		throw std::length_error("poziciqta koqto se opitvate da dostignete ne sas6testvuva");
}


template<typename T>
int Vector<T>::size()
{
	return m_size;
}
template<typename T>
int Vector<T>::capacity()
{
	return m_capacity;
}
template<typename T>
bool Vector<T>::empty()
{
	if (m_size == 0)
		return true;
	else
		return false;
}

template<typename T>
void Vector<T>::clear()
{
	m_size = 0;
}

template<typename T>
void Vector<T>::assign(int n, T value)
{
	if (m_size>0)
		clear();
	for (int i = 0; i < n; i++)
		push_back(value);
}
template<typename T>
void Vector<T>::assign(iterator it1, iterator it2)
{
	if (m_size>0)
		clear();
	for (it1; it1 != it2;it1++)
		push_back(*it1);
}

template<typename T>
void Vector<T>::assign(T* p1, T* p2)
{
	if (m_size>0)
		clear();
	for (p1; p1 != p2; p1++)
		this->push_back(*p1);
}