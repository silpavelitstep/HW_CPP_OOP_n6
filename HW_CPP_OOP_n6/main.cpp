#include <iostream>
#include "classes6.h"
using namespace std;
void task1();
void task2();//black jack
void task3();
void stop();//
int main() {
	task3();
	
	stop();
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
void task2() {
	player player1(10);//take 100$ money from bank
	casino acasino;//go to a casino
	cout << "How much desk? (1..8)\n>";
	int deskCount;
	cin >> deskCount;
	if (deskCount < 1 || deskCount>8)
		deskCount = 1;
	DeskOfCard doc(deskCount);//go to black jack table, select mode.
	//doc.show();
	cout << "diller: Hello, sir!\n";
	char select = 'y';
	while (true) {
		//No I don't or money is no then end game
		cout << "diller: do you want to play?\n[press y or n key then enter]\n>";
		cin >> select;
		if (select == 'n' or !player1.showCash())
			break;
		else if (select == 'y')
			acasino.game21(player1, doc);//begin game
		else
			cout << "[Incorrect select]!\n";
	}
	cout << "cash= " << player1.showCash() << endl;
	cout << "diller: goodbye sir, come again!\n";
	 
	
	

}
void task3() {
	char str[] = "%d %f\n%d %f\n%c\t %c\n";
	myprint(str, 5, 11.7, 9, 89.78, 'a', 'b');
}
void stop() {
	char ps[100];
	cin.getline(ps,'\n');
}