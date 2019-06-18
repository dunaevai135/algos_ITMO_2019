#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <unordered_map>
#include <list>

using namespace std;
/**/
#include "edx-io.hpp"
#define cout io
#define cin io
/**/

long my_hash(long long value, long ht_size) {
	return abs((value * 47) ^ (value * 31)) % ht_size;
}

bool insert(long long*& ht, long long value, long ht_size) {
	long h = my_hash(value, ht_size);
	while (ht[h] != -1 && ht[h] != value) {
		if (++h == ht_size) {
			h = 0;
		}
	}
	if (ht[h] == value) {
		return false;
	}
	else {
		ht[h] = value;
		return true;
	}
}

int main() {
	long N;
	int A, Ac, Ad;
	long long X, B, Bc, Bd;

	cin >> N >> X >> A >> B >> Ac >> Bc >> Ad >> Bd;
	
	long long* ht = new long long[N * 2];

	for (long i = 0; i < N * 2; i++) {
		ht[i] = -1;
	}

	for (long i = 0; i < N; i++) {
		if (insert(ht, X, N * 2)) {
			A = (A + Ad) % 1000;
			B = (B + Bd) % 1000000000000000;
		}
		else {
			A = (A + Ac) % 1000;
			B = (B + Bc) % 1000000000000000;
		}
		X = (X * A + B) % 1000000000000000;
	}

	cout << X << " " << A << " " << B;

	return 0;
}