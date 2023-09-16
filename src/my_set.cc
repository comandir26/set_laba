#include<string>
#include<algorithm>//find не нужен

#include "my_set/my_set.h"
using namespace my_set;

template<typename T>
int my_set::element_is_there(T* data, int size, const T& value) {
	for (size_t i = 0; i < size; i++)
	{
		if (data[i] == value) return i;
	}
	return -1;
}

template<typename T>
T* get_unique_data(T* data, int size, int* new_size){
	/*Пока что простой способ, выделю столько памяти, сколько находится в массиве с повторениями,
	переносить данные в новый массива буду уникальные*/
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

template<typename T>
MySet<T>::MySet():_data(nullptr), _size(0) {}

template<typename T>
MySet<T>::MySet(T* data, int size){
	int* new_size = new int(0);

	_data = get_unique_data(data, size, new_size);

	_size = *new_size;

	delete new_size;
}

template<typename T>
MySet<T>::MySet(const MySet<T>& rhs):_size(rhs.get_size()), _data(new T[rhs.get_size()]){
	for (int i = 0; i < _size; i++)
	{
		_data[i] = rhs[i];
	}
}

template<typename T>
MySet<T>::~MySet() {
	delete[] _data;
	_size = 0;
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

template<typename T>
const T& MySet<T>::operator[](int index) {
	//Здесь проверка на правильный индекс
	return _data[index];
}

//Когда вызывается константный оператор?
template<typename T>
const T MySet<T>::operator[](int index) const {
	//Здесь проверка на правильный индекс
	return _data[index];
}

template<typename T>
MySet<T>& MySet<T>::operator+=(const MySet<T>& rhs) {
	//текущий об size = 2, {1,2}
	//rhs size = 2, {3,4}
	int new_size = _size + rhs.get_size();

	T* new_data = new T[new_size]();

	for (int i = 0; i < _size; ++i)
	{
		new_data[i] = _data[i];
	}
	int j = 0;
	for (int i = _size; i < new_size; ++i)
	{
		new_data[i] = rhs[j];
		++j;
	}


	delete[] _data;

	int* actual_size = new int(0);

	_data = get_unique_data(new_data, new_size, actual_size);

	delete[] new_data;

	_size = *actual_size;

	return *this;
}

template<typename T>
MySet<T>& MySet<T>::operator-=(const MySet<T>& rhs) {
	for (int i = 0; i < rhs.get_size(); i++)
	{
		int index = element_is_there(_data, _size, rhs[i]);
		if (index != -1) {

			this->remove(index);
		}
	}
	return *this;
}

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
*/
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


