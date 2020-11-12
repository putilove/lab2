#include "NVector.h"
#include <iostream>
using namespace std;
int main() {
	float scalar = 0;
	size_t size = 0;
	cout << "Input size first vector: ";
	size = input_control();
	NVector a(size);
	//NVector a(5);
	FillVector(a);
	cout << "First " << a;
	cout << "Input size second vector: ";
	size = input_control();
	NVector b(size);
	//cout << "Input scalar: ";
	//cin >> scalar;
	//NVector b(5);
	FillVector(b);
	cout << "Second " << b;
	NVector c(a);
	cout << "Copy(with copy-ctor) of first " << c;
	NVector d(5);
	d = b;
	cout << "Copy(with copy-assign) of second " << d;
	NVector e(a + b);
	cout << "Copy(with move-ctor) of second " << d;
	a += b;
	cout << "a+=b => a: " << a;
	b = a + b;	
	cout << "b = a+b => b: " << b;
		// Демонстрация обработки исключений
	try{
		NVector x(3); NVector y(4);
		x += y;
	}
	catch (logic_error) {
		cout << "Index out of range!";
	}
	b *= 5;
	cout << "b*=5 => b: " << b;
	//b *= scalar;
	d = d * 5;
	cout << "d = d * 5 => d: " << d;
	d /= 5;
	cout << "d/=5 => d: " << d;
	d = d / 5;
	cout << "d= d/5 => d: " << d;
	scalar = d * b;
	cout << "c=d*b(scalar multiply) => d: " << scalar << endl;
	cout << "a and b before swap: ";
	cout << a;
	cout << b;
	a.Swap(b);
	cout << "a and b after swap: ";
	cout << a;
	cout << b;
	cout << a[3] << endl;
	cout << "a[3] = 51.2" << endl;
	a[3] = 51.2;
	cout << a[3] << endl;
	return 0;
}