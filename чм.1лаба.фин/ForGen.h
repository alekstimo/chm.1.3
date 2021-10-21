#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include"Alg.h"
using namespace std;

void genVector(int n, double* arr, bool flag, int e) {
	if (!flag) n = n - 1;
	for (int i = 0; i < n; i++) {
		double el = 1.0137 * (2 * (rand() % e) - e);
		while (el == 0) {
			el = 1.0137 * (2 * (rand() % e) - e);
		}
		arr[i] = el;
	}
}


void genMatrix(int n, int k, double* a, double* b, double* c, double* p, double* q, double* f, double* xtt, int e) {
	genVector(n, a, true, e);
	genVector(n, b, false, e);
	genVector(n, c, false, e);
	genVector(n, p, true, e);
	genVector(n, q, true, e);
	genVector(n, f, true, e);
	genVector(n, xtt, true, e);
	if (!proverka(k, a, b, c, p, q, f)) {
		a[k] = q[k];
		p[k] = q[k];
		b[k - 1] = p[k - 1];
		b[k] = q[k + 1];
		c[k - 1] = q[k - 1];
		c[k] = p[k + 1];
	}
}