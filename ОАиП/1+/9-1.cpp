#include <iostream>
using namespace std;
float sqrt(float, float, float(*)(float));
float f1(float);
float f2(float);
void main()
{
	setlocale(LC_CTYPE, "Russian");
	float aa, bb;
	cout << "Введите a: " << endl;
	cin >> aa;
	cout << "Введите b: " << endl;
	cin >> bb;
	float* a = &aa;
	float* b = &bb;
	sqrt(*a, *b, f1);
	sqrt(*a, *b, f2);
}
float sqrt(float a, float b, float (*f)(float))
{
	float x, e = 0.001;
	do
	{
		x = (a + b) / 2;
		if (f(x) * f(a) <= 0)
			b = x;
		else a = x;
	}
	while (abs(a - b) > 2 * e);
	cout << x << endl;
	return x;
}
float f1(float x)
{
	float z = pow(x, 3) + x - 4;
	return z;
}
float f2(float x)
{
	float z = 1 - pow(x, 2);
	return z;
}