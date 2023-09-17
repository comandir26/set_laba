
/*#include<string>
#include<algorithm>//find не нужен

#include "my_set/my_set.h"
using namespace my_set;

template<typename T>
int element_is_there(T* data, int size, const T& value) {
	for (size_t i = 0; i < size; i++)
	{
		if (data[i] == value) return i;
	}
	return -1;
}

template<typename T>
T* get_unique_data(T* data, int size, int* new_size){
	/*Пока что простой способ, выделю столько памяти, сколько находится в массиве с повторениями,
	переносить данные в новый массива буду уникальные
	T* unique_data = new T[size]();
	int i = 0;
	int j = 0;
	while (i < size && j < size) {
		if (element_is_there(unique_data, *new_size, data[j]) == -1) {
			unique_data[i] = data[j];
			*new_size += 1;
			++i;
			++j;
		}
		else ++j;
	}
	return unique_data;
}

/*template<typename T>
MySet<T>::MySet(int size, T begin, T end):_size(size), _data(new int[size]()) {
	for (size_t i = 0; i < size; i++)
	{
		_data[i] = begin;
		begin += 1;
	}
}
*/


/*
template<typename T>
MySet<T> operator+(const MySet<T>& lhs, const MySet<T>& rhs) {
	MySet copy(lhs);
	return copy += rhs;
}

template<typename T>
MySet<T> operator-(const MySet<T>& lhs, const MySet<T>& rhs) {
	MySet copy(lhs);
	return copy -= rhs;
}


template<typename T>
MySet<T> MySet<T>::intersection(const MySet& rhs) {
	MySet copy(*this);
	for (int i = 0; i < copy.get_size(); i++)
	{
		int index = element_is_there(copy.get_data(), copy.get_size(), rhs[i]);
		if (index != -1) {
			copy.remove(index);
		}
	}
	return (*this - copy);
}

template<typename T>
void MySet<T>::remove(int index) {
	//проверка на правильный индекс
	for (int i = index; i < _size-1; i++)
	{
		T temp = _data[i];
		_data[i] = _data[i + 1];
		_data[i + 1] = temp;
	}
	_size--;
}

template class MySet<int>;
template class MySet<float>;
template class MySet<std::string>;
template class MySet<std::pair<int, double>>;
*/


