#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;
void readVector(ifstream& fin, int n, double* arr, bool flag) {
	if (!flag) n = n - 1;
	for (int i = 0; i < n; i++) {
		int k;
		fin >> k;
		arr[i] = k;
	}
}
void readFromFile(ifstream& fin, int& n, int& k, double* a, double* b, double* c, double* p, double* q, double* f) {
	readVector(fin, n, a, true);
	readVector(fin, n, b, false);
	readVector(fin, n, c, false);
	readVector(fin, n, p, true);
	readVector(fin, n, q, true);
	readVector(fin, n, f, true);
}