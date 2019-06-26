#include "classes6.h"
#include <stdlib.h>
#include <time.h>

//complex
complex complex::operator+(complex lx) {
	complex cx;
	cx.image = this->image + lx.image;
	cx.real = this->real + lx.real;
	return cx;
}
complex complex::operator-(complex lx) {
	complex cx;
	cx.image = this->image - lx.image;
	cx.real = this->real - lx.real;
	return cx;
}
ostream& operator<<(ostream& out, complex& lx) {
	if (lx.real) out << lx.real;//for 0+7i
	if (lx.image) {
		if (lx.image > 0) out << '+';//for 5_4i
		if (lx.image != 1) out << lx.image;//for 4-i
		out << 'i';
	}
	return out;
}
complex complex::operator*(complex lx) {
	//(a+bi)(c+di)=(ac-bd)+(bc+ad)i
	complex cx;
	cx.real = this->real * lx.real - this->image * lx.image;
	cx.image = this->image * lx.real + this->real * lx.image;
	return cx;
}
complex complex::operator/(complex lx) {
	complex cx;
	//(a+bi)/(c+di) c^2+d^2 != 0
	double a = this->real;
	double b = this->image;
	double c = lx.real;
	double d = lx.image;
	double zer = c * c + d * d;
	if (zer ==0 ) return 0;
	cx.real = (a * c + b * d) / zer;
	cx.image = (b * c - a * d) / zer;
	return cx;
}
istream &operator>>(istream& in, complex& lx) {
	cin >> lx.real;
	cin >> lx.image;
	return in;
}
bool complex::operator==(complex lx) {
	return this->real == lx.real && this->image == this->image;
}
/////////////////////////////////////////
// 21
void casino::game21(player &pl, DeskOfCard& doc) {
	cout << "=====+=====+=====\n";
	cout << "diller: new round!\n";
	cout << "I have "<<pl.showCash()<<"$ money.\n";
	cout << "diller: put your money for round\n>";
	double rate;
	cin >> rate;
	if (rate > pl.showCash()) {
		cout << "Incorrect rate!\n";
		cout << "=====+=====+=====\n";
		return;
	}
	cout << "You cards, please^.\n";
	srand(time(0));
	//player and diller take two cards each.
	pl.takeCard(doc);
	pl.takeCard(doc);
	player pl2(0);
	pl2.takeCard(doc);
	pl2.takeCard(doc);
	cout << "score= " << pl.score() << endl;
	cout << "score= " << pl2.score() << endl;
	cout << "=====+=====+=====\n";
}
void player::takeCard(DeskOfCard& doc) {
	int rndcard;
	//generation new card
	do {
		rndcard = rand() % 13;
	} while (doc.card[2][rndcard] == 0);
	//take the card from desk
	doc.card[2][rndcard]--;
	//give the card to player
	cardCount++;
	cards[0][cardCount]=doc.card[0][rndcard];//name
	cards[1][cardCount] = doc.card[1][rndcard];//price
}
int player::score() {
	int sum=0;
	//iter cards
	for (int i = 0; i <= cardCount; i++) {
		//show each
		if(cards[0][i])//!=10
			cout << cards[0][i] << "  ";
		else//=10
			cout << 10 << "  ";
		//calc sum
		if (sum >= 21 && cards[0][i] == 'A')//Ace is 10 or 1(>=21)
			sum += 1;
		else sum += cards[1][i];
	}
	cout << endl;
	return sum;
}

void DeskOfCard::show() {
	for (int j = 0; j < 13; j++)
		cout << card[0][j] << ' ';
	cout << endl;
	for (int i = 1; i < 3; i++) {
		
		for (int j = 0; j < 13; j++) {
			cout << (int)card[i][j] << ' ';
		}
		cout << endl;
	}
}
