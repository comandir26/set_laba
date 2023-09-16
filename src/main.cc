#include <iostream>
#include "my_set/my_set.h"
using namespace my_set;
using namespace std;

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

int main() {

	int array1[] = {1, 2, 5, 4};
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

	auto dif = set1 - set2;

	auto inter = set1.intersection(set2);

	for (size_t i = 0; i < inter.get_size(); i++)
	{
		cout << inter[i] << ' ';
	}
	cout << '\n';

	return 0;
	
}