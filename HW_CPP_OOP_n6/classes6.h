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
#endif
