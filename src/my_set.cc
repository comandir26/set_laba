#include<string>
#include<algorithm>//find не нужен

#include "my_set/my_set.h"
using namespace my_set;

template<typename T>
bool element_is_there(T* data, int size, const T& value) {
	for (size_t i = 0; i < size; i++)
	{
		if (data[i] == value) return true;
	}
	return false;
}

template<typename T>
T* get_unique_data(T* data, int size, int* new_size){
	/*ѕока что простой способ, выделю столько пам€ти, сколько находитс€ в массиве с повторени€ми,
	переносить данные в новый массива буду уникальные*/
	T* unique_data = new T[size]();
	int i = 0;
	int j = 0;
	while (i < size && j < size) {
		if (element_is_there(unique_data, *new_size, data[j]) == false) {
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
T& MySet<T>::operator[](int index) {
	//«десь проверка на правильный индекс
	return _data[index];
}

// огда вызываетс€ константный оператор?
template<typename T>
const T MySet<T>::operator[](int index) const {
	//«десь проверка на правильный индекс
	return _data[index];
}



template class MySet<int>;
template class MySet<float>;
template class MySet<std::string>;
template class MySet<std::pair<int, double>>;