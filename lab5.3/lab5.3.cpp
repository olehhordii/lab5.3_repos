// lab5.3.cpp 
// Гордій Олег IK-11
#include <iostream>
#include <cmath>
using namespace std;
double h(const double x);
int main()
{
	double qp, qk, z;
	int n;
	
	cout << "qp = "; cin >> qp;
	cout << "qk = "; cin >> qk;
	cout << "n = "; cin >> n;
	double dq = (qk - qp) / n;
	double q = qp;
	while (q <= qk)
	{
		z = h(q+1) + h(q*q+1)+pow(h(q*q),2);
		cout << q << " " << z << endl;
		q += dq;
	}
	return 0;
}
double h(const double x)
{
	if (abs(x) >= 1)
		return (cos(x)+1)/(pow(cos(x),2)+1);
	else
	{
		double S = 0;
		int i = 0;
		double a = 1;
		S = a;
		do
		{
			i++;
			double R = x * x / ((2 * i - 2) * (2 * i - 1) * 2 * i);
			a *= R;
			S += a*(1/cos(x));
		} while (i < 6);
		return S;
	}
}
