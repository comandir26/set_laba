#include <iostream>
#include "my_set/my_set.h"
using namespace my_set;
using std::cout;

int main() {
	int array[] = {1, 2, 2, 1};
	auto set = MySet<int>(array, 4);
	for (size_t i = 0; i < set.get_size(); i++)
	{
		cout << set[i] << ' ';
	}
	return 0;
}