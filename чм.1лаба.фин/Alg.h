#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;


void edinica(int i, int k, int n, double* a, double* b, double* c, double* p, double* q, double* f, double* ft, double* ftt);
void resToOne(int k, int n, double* a, double* b, double* c, double* p, double* q, double* x, double* f);
void obnulSnizu(int i, int k, int n, double* a, double* b, double* c, double* p, double* q, double* f, double* ft, double* ftt);
void print(int k, int n, double* a, double* b, double* c, double* p, double* q, double* f);
void print(int n, double* x);
double delta(int n, double* ftt);
double delta(int n, double q, double* ftt, double* xtt);
void obnulSverhu(int i, int k, double* a, double* b, double* c, double* p, double* q, double* f, double* ft, double* ftt);
void rabota(int k, int n, double* a, double* b, double* c, double* p, double* q, double* f, double* ft, double* ftt, double* x, double* xtt);
void result(int n, double* f, double* ftt, double* x, double* xtt);
bool proverka(int k, double* a, double* b, double* c, double* p, double* q, double* f);
double SearchQ(int n, double* f);


double SearchQ(int n, double* f) {
	double q=f[0];
	for (int i = 0; i < n; i++) {
		if (q < f[i])
			q = f[i];
	}
	return q;
}
double delta(int n, double q, double* ftt, double *xtt) {
	double d = 0;
	for (int i = 0; i < n; i++) {
		if (abs(xtt[i] > q)) {
			double pr = abs((ftt[i] - xtt[i]) / xtt[i]);
			if (pr > d)
				d = pr;
		}
		else {
			double pr = abs(ftt[i] - xtt[i]);
			if (pr > d)
				d = pr;
		}
	}
	return d;

}

double delta(int n, double* ftt) {
	double d = 0;
	for (int i = 0; i < n; i++) {
		if (abs(ftt[i] - 1) > d)
			d = abs(ftt[i] - 1);
	}
	return d;
}
void resToOne(int k, int n, double* a, double* b, double* c, double* p, double* q, double* x, double* f) {
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			f[i] = a[i] * x[i] + b[i] * x[i + 1];
			if (i != k - 1) {
				f[i] = f[i] + p[i] * x[k];
			}
		}
		else if (i == n - 1)
		{
			f[i] = a[i] * x[i] + c[i - 1] * x[i - 1];
			if (i != k + 1) {
				f[i] = f[i] + p[i] * x[k];
			}
		}
		else if (i == k) {
			f[i] = 0;
			for (int j = 0; j < n; j++) {
				f[i] = f[i] + q[j] * x[j];
			}
		}
		else if ((i == k - 1) || (i == k + 1)) {
			f[i] = a[i] * x[i] + b[i] * x[i + 1] + c[i - 1] * x[i - 1];
		}

		else {
			f[i] = a[i] * x[i] + b[i] * x[i + 1] + c[i - 1] * x[i - 1] + p[i] * x[k];
		}
	}
}

void print(int n, double* x) {
	for (int i = 0; i < n; i++) {
		cout << fixed << setprecision(20) << x[i] << endl;
	}
	cout << endl;
}

void print(int k, int n, double* a, double* b, double* c, double* p, double* q, double* f) {
	for (int i = 0; i < n; i++) {
		cout << setprecision(3) << '|';
		for (int j = 0; j < n; j++) {
			if (j == k)
				cout << p[i] << setprecision(3) << "\t";
			else if (i == k) {
				for (int m = 0; m < n; m++) {
					cout << q[m] << setprecision(3) << "\t";
				}
				break;
			}
			else if (i == j + 1) {
				/*if (i == n-1) {
				cout << c[i - 1];
				}
				else*/
				cout << c[i - 1] << setprecision(3) << "\t";
			}
			else if (i == j)
				cout << a[i] << setprecision(3) << "\t";
			else if (i == j - 1)
				cout << b[i] << setprecision(3) << "\t";
			else
				cout << "0" << "\t";
		}
		cout << '=';
		cout << f[i] << setprecision(3) << "\t";
		cout << '|';
		cout << endl;
	}
	cout << "----------------------------" << endl;
	cout << endl;

}
void result(int n, double* f,  double* x) {
	for (int i = 0; i < n; i++) {
		x[i] = f[i];
		//xtt[i] = ftt[i];
	}
}
//double showDecimals(const double& x, const int& numDecimals) {
//    int y = x;
//    double z = x - y;
//    double m = pow(10, numDecimals);
//    double q = z * m;
//    double r = round(q);
//
//    return static_cast<double>(y) + (1.0 / m) * r;
//}
void rabota(int k, int n, double* a, double* b, double* c, double* p, double* q, double* f, double* ft, double* ftt, double* x) {
	for (int i = 0; i < k; i++) {
		edinica(i, k, n, a, b, c, p, q, f, ft, ftt);
		obnulSnizu(i, k, n, a, b, c, p, q, f, ft, ftt);
	}

	/*cout << "OBLUL SNIZU DO K" << endl;
	cout << endl;

	cout << "F~ = " << endl;
	print(n, ft);
	cout << endl;*/

	for (int i = n - 1; i > k; i--) {
		edinica(i, k, n, a, b, c, p, q, f, ft, ftt);
		obnulSverhu(i, k, a, b, c, p, q, f, ft, ftt);
	}
	/*cout << "OBLUL SVERHU POSLE K" << endl;
	cout << endl;
	cout << "F~ = " << endl;
	print(n, ft);
	cout << endl;*/
	edinica(k, k, n, a, b, c, p, q, f, ft, ftt);
	for (int i = k; i < n - 1; i++) {
		obnulSnizu(i, k, n, a, b, c, p, q, f, ft, ftt);
	}
	/*cout << "OBLUL SNIZU POSLE K" << endl;
	cout << endl;
	cout << "F~ = " << endl;
	/*print(n, ft);
	cout << endl;*/
	for (int i = k; i > 0; i--) {
		obnulSverhu(i, k, a, b, c, p, q, f, ft, ftt);
	}
	result(n, f, x);
}
bool proverka(int k, double* a, double* b, double* c, double* p, double* q, double* f) {
	if ((a[k] == p[k]) && (a[k] == q[k]) && (b[k - 1] == p[k - 1]) && (b[k] == q[k + 1]) && (c[k - 1] == q[k - 1]) && (c[k] == p[k + 1]))
		return 1;
	return 0;
}
void edinica(int i, int k, int n, double* a, double* b, double* c, double* p, double* q, double* f, double* ft, double* ftt) {
	double koef(a[i]);
	a[i] = a[i] / a[i];
	p[i] = p[i] / koef;
	f[i] = f[i] / koef;
	ft[i] = ft[i] / koef;
	ftt[i] = ftt[i] / koef;
	if (i <= k) {
		b[i] = b[i] / koef;
		if (i == k) {
			q[i] = a[i];
		}
	}
	else {
		c[i - 1] = c[i - 1] / koef;
	}
}

void obnulSnizu(int i, int k, int n, double* a, double* b, double* c, double* p, double* q, double* f, double* ft, double* ftt) {
	if (i < k) {
		double koef(c[i]);
		c[i] = c[i] - koef * a[i];
		a[i + 1] = a[i + 1] - koef * b[i];
		p[i + 1] = p[i + 1] - koef * p[i];
		f[i + 1] = f[i + 1] - koef * f[i];
		ft[i + 1] = ft[i + 1] - koef * ft[i];
		ftt[i + 1] = ftt[i + 1] - koef * ftt[i];
		if (i != k - 1) {
			koef = q[i];
			q[i] = q[i] - koef * a[i];
			q[i + 1] = q[i + 1] - koef * b[i];
			p[k] = a[k] = q[k] = q[k] - koef * p[i];
			f[k] = f[k] - koef * f[i];
			ft[k] = ft[k] - koef * ft[i];
			ftt[k] = ftt[k] - koef * ftt[i];
		}
		else {
			q[i + 1] = p[i + 1];
			q[i] = c[i];
		}
		if (i == k - 2) {
			b[i + 1] = p[i + 1];
			c[i + 1] = q[i + 1];
		}
	}
	else if (i == k) {
		for (int j = k; j < n - 1; j++) {
			double koef(p[j + 1]);
			p[j + 1] = p[j + 1] - koef * p[k];
			if (j == k) {
				c[j] = p[j + 1];
			}
			f[j + 1] = f[j + 1] - koef * f[k];
			ft[j + 1] = ft[j + 1] - koef * ft[k];
			ftt[j + 1] = ftt[j + 1] - koef * ftt[k];
		}
	}
	else {
		double koef(c[i]);
		c[i] = c[i] - koef * a[i];
		f[i + 1] = f[i + 1] - koef * f[i];
		ft[i + 1] = ft[i + 1] - koef * ft[i];
		ftt[i + 1] = ftt[i + 1] - koef * ftt[i];
	}
}

void obnulSverhu(int i, int k, double* a, double* b, double* c, double* p, double* q, double* f, double* ft, double* ftt) {
	double koef(b[i - 1]);
	b[i - 1] = b[i - 1] - koef * a[i];
	f[i - 1] = f[i - 1] - koef * f[i];
	ft[i - 1] = ft[i - 1] - koef * ft[i];
	ftt[i - 1] = ftt[i - 1] - koef * ftt[i];
	if (i > k) {
		a[i - 1] = a[i - 1] - koef * c[i - 1];
		p[i - 1] = p[i - 1] - koef * p[i];
		koef = q[i];
		q[i] = q[i] - koef * a[i];
		q[i - 1] = q[i - 1] - koef * c[i - 1];

		if (i != k + 1) {
			q[k] = a[k] = p[k] = p[k] - koef * p[i];
			f[k] = f[k] - koef * f[i];
			ft[k] = ft[k] - koef * ft[i];
			ftt[k] = ftt[k] - koef * ftt[i];
		}
		if (i == k + 2) {
			c[i - 2] = p[i - 1];
			b[i - 2] = q[i - 1];
		}
	}
	else if (i == k) {
		p[i - 1] = b[i - 1];
		for (int j = k - 2; j >= 0; j--) {
			koef = p[j];
			p[j] = p[j] - koef * p[k];
			f[j] = f[j] - koef * f[k];
			ft[j] = ft[j] - koef * ft[k];
			ftt[j] = ftt[j] - koef * ftt[k];
		}
	}

}
