#include <iostream>
using namespace std;

class Comlex {
	double a;
	double b;
public:
	Comlex(double _a, double _b);
	Comlex& operator+(Comlex& com);
	Comlex& operator-(Comlex& com);
	Comlex& operator*(Comlex& com);
	Comlex& operator/(Comlex& com);
	friend ostream& operator<<(ostream& out, const Comlex& com);
};
ostream& operator<<(ostream& out, const Comlex& com){
	out <<  com.a << " + " << com.b << "i" << endl;
	return out;
}
Comlex::Comlex(double _a, double _b)
:a(_a),b(_b)
{}
Comlex& Comlex::operator+(Comlex& com){
	a += com.a;
	b += com.b;
	return *this;
}
Comlex& Comlex::operator-(Comlex& com) {
	a -= com.a;
	b - +com.b;
	return *this;
}
Comlex& Comlex::operator*(Comlex& com) {
	a = a * com.a - b * com.b;
	b = a * com.b + com.a * b;
	return *this;
}
Comlex& Comlex::operator/(Comlex& com) {
	a = (a * com.a + b * com.b) / com.a * com.a + com.b * com.b;
	b = (b * com.a - a * com.b) / com.a * com.a + com.b * com.b;

	return *this;
}

int main()
{
	setlocale(0, "");
	Comlex z1(10.4, 15.9);
	Comlex z2(5.15, 3.03);
	cout << "Даны два комлексных числа: " << endl;
	cout << "z1 = " << z1;
	cout << "z2 = " << z2;
	cout << "Сложение двух комлексных чисел: " << endl;
	cout << "z = " << z1 + z2;
	cout << "Вычитание двух комлексных чисел: " << endl;
	cout << "z = " << z1 - z2;
	cout << "Умножение двух комлексных чисел: " << endl;
	cout << "z = " << z1 * z2;
	cout << "Деление двух комлексных чисел: " << endl;
	cout << "z = " << z1 / z2;
}
