#include <iostream>
#include <string>
#include <utility>
#include "my_set/my_set.h"
using namespace my_set;
using namespace std;

int main(){
	int iarray[] = {1, 3, 2, 5, 6, 3, 5, 9};//8
	float farray[] = { 1.12, 2.33, 1.45, 5.76, 6.34, 2.33, 2.33, 9.875 };//8
	string sarray[] = { "python", "aisd", "laptop", "python" };//4
	pair<int, double> parray[] = { make_pair(1, 1.12), make_pair(5, 3.12), make_pair(3, 7.12), make_pair(9, 4.12), make_pair(5, 3.12) };//5

	auto iset1 = MySet<int>(iarray, 8);
	auto fset1 = MySet<float>(farray, 8);
	auto sset1 = MySet<string>(sarray, 4);
	auto pset1 = MySet<pair<int, double>>(parray, 5);

	auto repeats = iset1.get_all_repeats(iarray, 8);

	cout << iset1;
	cout << repeats;
	cout << fset1;
	cout << sset1;
	cout << pset1;

	return 0;	
}