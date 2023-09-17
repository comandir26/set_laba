#include <iostream>
#include <string>
#include "my_set/my_set.h"
using namespace my_set;
using namespace std;

/*template<typename T>
int element_is_there(T* data, int size, const T& value) {
	for (size_t i = 0; i < size; i++)
	{
		if (data[i] == value) return i;
	}
	return -1;
}*/

/*template<typename T>
T* get_unique_data(T* data, int size, int* new_size) {
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
MySet<T> intersection(const MySet<T>& lhs, const MySet<T>& rhs) {
	MySet copy(lhs);
	for (int i = 0; i < copy.get_size(); i++)
	{
		int index = element_is_there(copy.get_data(), copy.get_size(), rhs[i]);
		if (index != -1) {
			copy.remove(index);
		}
	}
	return (lhs - copy);
}*/

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
MySet<T> operator+(const MySet<T>& lhs, const T& value) {
	MySet copy(lhs);
	return copy += value;
}

template<typename T>
MySet<T> operator-(const MySet<T>& lhs, const T& value) {
	MySet copy(lhs);
	return copy -= value;
}

int main() {

	int array1[] = {1, 6, 5, 4};
	int array2[] = {2, 3, 4, 9};
	auto set1 = MySet<int>(array1, 4);
	auto set2 = MySet<int>(array2, 4);
	
	/*
	float array3[] = { 1.1, 2.3, 5.4 };
	float array4[] = { 5.4, 2.2, 1.7 };
	auto set3 = MySet<float>(array3, 3);
	auto set4 = MySet<float>(array4, 3);

	auto sumi = set1 + set2;
	auto sumf = set3 + set4;

	*/

	auto set3 = set1 + 7;

	auto set4 = set2 - 4;

	auto dif = set3 - set4;

	auto inter = set1.intersection(set2);

	auto sum = set1 + set2;	

	for (size_t i = 0; i < dif.get_size(); i++)
	{
		cout << dif[i] << ' ';
	}

	return 0;	
}