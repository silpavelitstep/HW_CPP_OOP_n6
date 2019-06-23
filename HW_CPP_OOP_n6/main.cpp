#include <iostream>
#include "classes6.h"
using namespace std;
void task1();
int main() {
	task1();
	//system("pause");
	return 0;
}
void task1() {
	complex lx1(10, -6);
	complex lx2(0, -10);
	complex lxres;
	cout << lx1 << endl;
	cout << '+' << endl;
	cout << lx2 << endl;
	cout << '=' << endl;
	lxres = lx1 + lx2;
	cout << lxres << endl;
	cout << "----------------\n";
	cout << '-' << endl;
	cout << '=' << endl;
	lxres = lx1 - lx2;
	cout << lxres << endl;
	cout << "----------------\n";
	cout << '*' << endl;
	cout << '=' << endl;
	lxres = lx1 * lx2;
	cout << lxres << endl;
	cout << "----------------\n";
	cout << '/' << endl;
	cout << '=' << endl;
	lxres = lx1 / lx2;
	cout << lxres << endl;
	cout << "----------------\n";
	//cin >> lx1;
	//cout << lx1;
	complex lx3(10, -16);
	bool res = (lx1 == lx3);
	cout << res << endl;
	lxres.set(8, -9);
	cout << lxres << endl;
}