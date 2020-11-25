#include "NVector.h"
#include <iostream>
using namespace std;
int main() {
	try {
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
		if (a == b) cout << "a==b" << endl;
		else cout << "a!=b" << endl;
		cout << "----------------------------------------------------------" << endl;
		NVector c(a);		
		cout << "Copy(with copy-ctor) of first " << c;
		cout << "----------------------------------------------------------" << endl;
		NVector d(5);
		d = b;
		cout << "Copy(with copy-assign) of second " << d;
		cout << "----------------------------------------------------------" << endl;
		NVector e(a + b);
		cout << "Copy(with move-ctor) of second ";
		cout << "----------------------------------------------------------" << endl;
		a += b;
		cout << "a+=b => a: " << a;
		cout << "----------------------------------------------------------" << endl;
		b = a + b;
		cout << "b = a+b => b: " << b;
		// Демонстрация обработки исключений
		//NVector x(3); NVector y(4);
		//x += y;
		cout << "----------------------------------------------------------" << endl;
		b *= 5;
		cout << "b*=5 => b: " << b;
		//b *= scalar;
		cout << "----------------------------------------------------------" << endl;
		d = d * 5;
		cout << "d = d * 5 => d: " << d;
		cout << "----------------------------------------------------------" << endl;
		d /= 5;
		cout << "d/=5 => d: " << d;
		cout << "----------------------------------------------------------" << endl;
		d = d / 5;
		cout << "d= d/5 => d: " << d;
		cout << "----------------------------------------------------------" << endl;
		scalar = d * b;
		cout << "scalar=d*b(scalar multiply) => d: " << scalar << endl;
		cout << "----------------------------------------------------------" << endl;
		cout << "a and b before swap: ";
		cout << a;
		cout << b;
		a.Swap(b);
		cout << "a and b after swap: ";
		cout << a;
		cout << b;
		cout << "----------------------------------------------------------" << endl;
		cout << a[0] << endl;
		cout << "a[3] = 51.2" << endl;
		a[0] = 51.2;
		cout << a[0] << endl;
	}
	catch (logic_error &error) {
		cout << error.what() << endl;
	}
	return 0;
}