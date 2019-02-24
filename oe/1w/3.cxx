#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <inttypes.h>

using namespace std;

int main () {
	ifstream fi;
	ofstream fo;
	size_t n;
	int tmp;
	vector<int> v;
	fi.open ("input.txt");
	fo.open ("output.txt");
	fi >> n;
	for (size_t i = 0; i < n; ++i) {
		fi >> tmp;
		v.push_back(tmp);
	}

	fo << 1 << " ";

	for (size_t i = 1; i < n; ++i) {
		int key = v[i];
		int j = i-1;
		while (j >= 0 and v[j] > key) {
			v[j+1] = v[j];
			j--;
		}
		v[j+1] = key;
		fo << j + 2<< " ";// TODO magic consts
	}

	fo << "\n";

	for (size_t i = 0; i < n; ++i) {
		fo << v[i] << " ";
	}

	fi.close();
	fo.close();
	return 0;
}