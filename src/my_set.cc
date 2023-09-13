#include<string>
#include<algorithm>
//#include<utility> библиотека для пары
#include "my_set/my_set.h"
using namespace std;
using namespace my_set;

/*template<typename T>
bool find_value(int* data, int value) {
	auto result = find(begin(data), end(data), value);
	return (result == end(data)) ? true : false;
}*/

template<typename T>
MySet<T>::MySet():_data(nullptr) {}

template<typename T>
MySet<T>::MySet(T* data, size_t size): _data(new T[size]), _size(size) {
	for (size_t i = 0; i < size-1; i++)
	{
		/*if (find_value(_data, data[i])) {
			_data[i] = data[i];
		}*/
		_data[i] = data[i];
	}
}

template class MySet<int>;
template class MySet<float>;
template class MySet<std::string>;
template class MySet<std::pair<int, double>>;