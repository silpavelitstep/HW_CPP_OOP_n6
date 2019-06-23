#include "classes6.h"
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
