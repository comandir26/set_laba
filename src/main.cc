#include <iostream>
#include <string>
#include <utility>
#include "my_set/my_set.h"
using namespace my_set;
using namespace std;

int main(){
	int iarray1[] = {1, 3, 2, 5, 6, 6 ,6,2,1};//5
	int iarray2[] = {4, 5, 7, 8, 9};//5
	float farray1[] = { 1.12, 2.33, 1.45, 5.76, 2.33, 2.33, 9.875 };//7
	float farray2[] = { 1.34, 3.23, 1.45, 5.76, 8.34};//5
	string sarray[] = { "python", "aisd", "laptop", "python" };//4
	pair<int, double> parray1[] = { make_pair(1, 1.12), make_pair(5, 3.12), make_pair(3, 7.12), make_pair(9, 4.12), make_pair(5, 3.12) };//5
	pair<int, double> parray2[] = { make_pair(3, 1.12), make_pair(5, 3.12), make_pair(1, 1.12), make_pair(5, 7.12), make_pair(6, 8.88) };//5

	auto iset1 = MySet<int>(iarray1, 9);
	auto iset2 = MySet<int>(iarray2, 5);

	auto fset1 = MySet<float>(farray1, 7);
	auto fset2 = MySet<float>(farray2, 5);

	auto sset1 = MySet<string>(sarray, 4);

	auto pset1 = MySet<pair<int, double>>(parray1, 5);
	auto pset2 = MySet<pair<int, double>>(parray2, 5);

	//auto repeats = iset1.get_all_repeats(iarray1, 8);

	cout << "Set of int" << "\n";
	cout << iset1 << "\n\n";
	cout << "Set of float" << "\n";
	cout << fset1 << "\n\n";
	cout << "Set of string" << "\n";
	cout << sset1 << "\n\n";
	cout << "Set of pair" << "\n";
	cout << pset1 << "\n\n";

	cout << "Sum of sets(int):" << "\n";
	cout << iset1 << " + " << iset2 << " = ";
	auto sum = iset1 + iset2;
	cout << sum;
	cout << "\n\n";
	
	cout << "Difference of sets(float):" << "\n";
	cout << fset1 << " - " << fset2 << " = ";
	auto dif = fset1 - fset2;
	cout << dif;
	cout << "\n\n";

	cout << "+= and -= with string set:\n";
	cout << sset1 << "\n";
	sset1 += "samara";
	sset1 -= "laptop";
	cout << sset1;
	cout << "\n\n";

	cout << "Difference of sets(pair):" << "\n";
	cout << pset1 << " - " << pset2 << " = ";
	auto dif_pair = pset1 - pset2;
	cout << dif_pair;
	cout << "\n\n";

	cout << "Intersection of sets(int):" << "\n";
	cout << iset1 << ",  " << iset2 << " = ";
	auto inter_int = iset1.intersection(iset2);
	cout << inter_int;
	cout << "\n\n";

	cout << "get all repeats: ";
	int array3[] = { 1, 2, 3, 2, 1, 4, 5, 6, 7, 4, 9, 9 };
	for (size_t i = 0; i < 12; i++)
	{
		cout << array3[i] << " ";
	}
	cout << '\n';
	auto iset3 = MySet<int>(array3, 12);
	auto repeats = iset3.get_all_repeats(array3, 12);
	cout << "repeats: ";
	cout << repeats;
	cout << "\n\n";

	cout << "random c-or: \n";
	auto rset1 = MySet<int>(10, 1, 100);
	cout << rset1;

	return 0;	
}