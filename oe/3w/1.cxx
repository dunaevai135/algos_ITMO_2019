#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cstring>
#include <inttypes.h>

using namespace std;

void radix_sort(long *array, int n, long max_element) {
	auto *output = new long[n];
	auto *count = new long[256];

	for (int pow = 0; (1LL << pow) <= max_element; pow += 8) {
		memset(count, 0, sizeof(long) * 256);

		for (int i = 0; i < n; i++) {
			count[(array[i] >> pow) & 255]++;
		}

		for (int i = 1; i < 256; i++) {
			count[i] += count[i - 1];
		}

		for (int i = n - 1; i >= 0; i--) {
			output[--count[(array[i] >> pow) & 255]] = array[i];
		}

		for (int i = 0; i < n; i++) {
			array[i] = output[i];
		}
	}

	delete[] output;
	delete[] count;
}

int main() {
	int m, n;
	long max_element = -1;
	ifstream fi;
    ofstream fo;
	fi.open ("input.txt");
	fo.open ("output.txt");
	fi >> n >> m;
	auto *array = new long[n * m];
	auto *a = new long[n];
	auto *b = new long[m];

	for (int i = 0; i < n; i++) {
		fi >> a[i];
	}

	for (int i = 0; i < m; i++) {
		fi >> b[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			long c = a[i] * b[j];
			array[i * m + j] = c;
			max_element = max_element > c ? max_element : c;
		}
	}

	radix_sort(array, m*n, max_element);

	long long sum = 0;
	for (int i = 0; i < n * m; i += 10) {
		sum += array[i];
	}

	fo << sum;

	delete[] array;
	delete[] a;
	delete[] b;

	return 0;
}