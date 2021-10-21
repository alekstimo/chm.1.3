#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "ForFile.h"
#include "ForGen.h"
#include "Alg.h"
using namespace std;

void mainToFile(string str);
void mainToGen();

int main() {

	mainToFile("Текст.txt");
	mainToGen();
	system("Pause");
	return 0;
}

void mainToFile(string str) {
	ifstream fin(str);
	int n;
	int k;
	double* a, * b, * c, * p, * q, * f, * x, * ft, * ftt;
	double delt;
	if (!fin.is_open())
		cout<<"ERR"<<endl;
	else {
		fin >> n;
		fin >> k;
		a = new double[n];
		b = new double[n - 1];
		c = new double[n - 1];
		p = new double[n];
		q = new double[n];
		f = new double[n];
		ft = new double[n];
		for (int i = 0; i < n; i++) {
			ft[i] = 0;
		}
		ftt = new double[n];
		x = new double[n];
		for (int i = 0; i < n; i++) {
			x[i] = 1;
		}
		//xtt = new double[n];
		readFromFile(fin, n, k, a, b, c, p, q, f);
		cout << proverka(k, a, b, c, p, q, f) << endl;
		print(k, n, a, b, c, p, q, f);
		resToOne(k, n, a, b, c, p, q, x, ft);

		cout << "F~ = " << endl;
		print(n, ft);
		cout << endl;

		rabota(k, n, a, b, c, p, q, f, ft, ftt, x);


		cout << "X = " << endl;
		print(n, x);
		cout << endl;

		cout << "F~ = " << endl;
		print(n, ft);
		cout << endl;

		delt = delta(n, ft);
		cout << "OCENKA TOCNOSTI RESHENIA:" << endl;
		cout << " deltaX~ = " << delt << endl;
		cout << "_______________________________________" << endl;
	}
}
void mainToGen() {
	int n;
	int k;
	double* a, * b, * c, * p, * q, * f, * x, * xtt, * ft, * ftt;
	double delt, qt;
	n = 1000;
	k = 5;
	a = new double[n];
	b = new double[n - 1];
	c = new double[n - 1];
	p = new double[n];
	q = new double[n];
	f = new double[n];
	ft = new double[n]; //ср значение оценки точности
	for (int i = 0; i < n; i++) {
		ft[i] = 0;
	}
	ftt = new double[n]; //ср относительная погрешность
	for (int i = 0; i < n; i++) {
		ftt[i] = 0;
	}
	x = new double[n];
	for (int i = 0; i < n; i++) {
		x[i] = 1;
	}
	xtt = new double[n];
	genMatrix(n, k, a, b, c, p, q, f, xtt, 11);
	resToOne(k, n, a, b, c, p, q, x, ft);
	resToOne(k, n, a, b, c, p, q, xtt, ftt);
	qt = SearchQ(n, ftt);

	cout << "F~ sr znach ocenki tochosti (f pri X=1) = " << endl;
	print(n, ft);
	cout << endl;

	cout << "F~~ sr otnos pogreshnost (f pri Xtt) = " << endl;
	print(n, ftt);
	cout << endl;

	rabota(k, n, a, b, c, p, q, f, ft, ftt, x);

	cout << "______ANSWER_______" << endl;
	cout << "X = " << endl;
	print(n, x);
	cout << endl;

	cout << "X~ = (1,1 .. 1) " << endl;

	cout << "X~~ = " << endl;
	print(n, xtt);
	cout << endl;

	cout << "F~ sr znach ocenki tochosti (X=1) = " << endl;
	print(n, ft);
	cout << endl;

	cout << "F~~ sr otnos pogreshnost (XTT s pogr) = " << endl;
	print(n, ftt);
	cout << endl;

	delt = delta(n, ft);
	double deltftt = delta(n,qt, ftt,xtt);
	cout << "OCENKA TOCNOSTI RESHENIA:" << endl;
	cout << " deltaX~ = " << delt << endl;
	cout << "OTNOSITELNAYA POGRESHNOST:" << endl;
	cout << " deltaX~~ = " << deltftt << endl;
}
