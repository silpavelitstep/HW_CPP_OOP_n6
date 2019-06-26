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
	pl.zeroCard();//player without card with money
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
	pl.moveCash(-rate);//cash=cash-rate
	cout << "You cards, please^.\n";
	srand(time(0));
	//player and diller take two cards each.
	pl.takeCard(doc);
	pl.takeCard(doc);
	
	player diller(0,false);
	diller.takeCard(doc);
	diller.takeCard(doc);
	int playerScore = pl.score();//show
	cout << "player score= " << playerScore << endl;
	int dillerScore = diller.score();//not show
	
	cout << "diller score= " << dillerScore << endl;
	//=21 or >21 after 4 cards
	if (playerScore > 21) {
		cout << "you loser\n";
	}
	if (dillerScore > 21 && playerScore==21) {//21
		cout << "3 in 2.\n";
		pl.moveCash((int)rate * 1.5);
	}
	if (playerScore ==  dillerScore && dillerScore==21) {
		cout << "equals\n";
		pl.moveCash(rate);//cash=cash+rate
	}
	//<21 again card
	char select=' ';
	while (true) {
		cout << "Do you need a card?\n[press y or n key then enter]\n>";
		do {
			cin >> select;
		} while (select!='n' && select!='y');
		//player take or don't take a card
		if (select == 'y')
			pl.takeCard(doc);
		else
			break;//diller must not take card
		dillerScore = diller.score();
		cout << "diller score= " << dillerScore << endl;
		playerScore = pl.score();//show player cards
		cout << "player score= " << playerScore << endl;
		if (playerScore > 21) {
			cout << "you loser\n";
			return;//end round
		}
		if(playerScore==21)//21
			if (dillerScore == 21) {
				cout << "equals\n";
				pl.moveCash(rate);//cash=cash+rate
				return;//end round
			}
			else {
				cout << "3 in 2.\n";
				pl.moveCash((int)rate * 1.5);
				return;//end round
			}

		//if player taked a card but sum not 21
		//then diller take card if he need 
		if (dillerScore < 17)
			diller.takeCard(doc);
		dillerScore = diller.score();
		if (dillerScore == 21) {
			cout << "you loser\n";
			return;//end round
		}
	}
	//end while, last score;
	if (dillerScore > playerScore && dillerScore<=21) {
		cout << "you loser\n";
		return;//end round
	}
	if (dillerScore == playerScore && dillerScore<=21) {
		cout << "equals\n";
		pl.moveCash(rate);//cash=cash+rate
		return;//end round
	}
	if (dillerScore < playerScore && playerScore<=21) {
		cout << "3 in 2.\n";
		pl.moveCash((int)rate * 1.5);
	}

		
	
	
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
		//show each if not diller
		if (!isDiller) {//don't show diller cards
			if (cards[0][i] != '0')//!=10
				cout << cards[0][i] << "  ";
			else//=10
				cout << 10 << "  ";
		}
		//calc sum
		if (sum >= 21 && cards[0][i] == 'A')//Ace is 10 or 1(>=21)
			sum += 1;
		else sum += cards[1][i];
	}
	cout << endl;
	return sum;
}
void player::moveCash(int rate) {
	cash += rate;
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
