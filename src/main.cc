#include <iostream>
#include <string>
#include <utility>
#include "my_set/my_set.h"
using namespace my_set;
using namespace std;

int main() {
	int array1[] = {1, 2, 3, 4, 5, 6, 3, 4, 1};

	int array2[] = {3, 4, 6};

	pair<int, double> array3[] = {make_pair(1, 1.1), make_pair(2, 2.2), make_pair(3, 3.3)};

	MySet<int> set1 = MySet<int>(array1, 5);

	MySet<int> set2 = MySet<int>(array2, 3);

	MySet<float> set3 = MySet<float>(10, 1.0, 5.0);

	MySet<int> set4 = MySet<int>(10, 1, 100);
 
	cout << set3;

	cout << set4;
	
	return 0;	
}