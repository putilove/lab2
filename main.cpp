#include "NVector.h"
#include <iostream>
using namespace std;
int main() {
	size_t size = 0;
	cout << "Input size first vector: ";
	//cin >> size;
	//NVector a(size);
	NVector a(5);
	FillVector(a);
	cout << "First " << a;
	cout << "Input size second vector: ";
	//cin >> size;
	//NVector b(size);
	NVector b(5);
	FillVector(b);
	cout << "Second "<< b;
	NVector c(a);
	cout << "Copy(with copy-ctor) of first " << c;
	NVector d(5);
	d = b;
	cout << "Copy(with copy-assign) of second " << d;
	NVector e(a+b);
	cout << "Copy(with move-ctor) of second " << d;
}