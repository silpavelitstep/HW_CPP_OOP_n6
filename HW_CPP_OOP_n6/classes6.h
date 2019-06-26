#pragma once
#ifndef CLASSES6_H
#define CLASSES6_H
#include <iostream>
using namespace std;
class complex {
	double image;
	double real;
public:
	complex(int r, int i=0) :image(i), real(r) {}
	complex() :image(0), real(0) {}
	complex operator+(complex lx);
	complex operator-(complex lx);
	friend ostream& operator<<(ostream&, complex&);
	complex operator*(complex lx);
	complex operator/(complex lx);
	friend istream &operator>>(istream&, complex&);
	bool operator==(complex lx);
	void set(double re, double im) { real = re; image = im; };
	double getReal() { return real; };
	double getImage() { return image;};

};

class DeskOfCard {
public:
	int desk;//count of desk, max 8
	// index  0   1   2 3 4 5 6 7 8 9  10 11 12 
	// name   K   A   2 3 4 5 6 7 8 9   0  J  Q
	//score  10 11(1) 2 3 4 5 6 7 8 9  10 10 10
	// count  4   4   4 4 4 4 4 4 4 4   4  4  4 in every desk
	//count of cards and score of card
	char card[3][13] =
	{ {'K','A','2','3','4','5','6','7','8','9','0','J','Q'},
	 {10,11,2,3,4,5,6,7,8,9,10,10,10},
	 {4,  4,4,4,4,4,4,4,4,4, 4, 4, 4} };
	DeskOfCard(int desk) :desk(desk) {};
	void show();
};
class player {
	int cash;
	int cardCount;
	char cards[2][15];
public:
	player(int cash) :cash(cash), cardCount(-1) {}
	int showCash() { return cash; }
	void takeCard(DeskOfCard& doc);
	int score();
	
};
class diller {
public:
};
class casino{
public:
	void game21(player &pl, DeskOfCard &doc);
};
#endif
