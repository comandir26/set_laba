#include <iostream>
#include <vector>
#include "my_set/my_set.h"
using namespace my_set;
using namespace std;

int main() {
	int array[] = { 1, 2, 3 };
	int size = end(array) - begin(array);
	auto set = MySet<int>(array, size);
	return 0;
}