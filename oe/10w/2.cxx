#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <list>

using namespace std;
/**/
#include "edx-io.hpp"
#define cout io
#define cin io
/**/

vector<int> calc_z(string s) {
	vector<int> z(s.length(), 0);
	for (int i = 1, l = 0, r = 0; i < s.length(); i++) {
		if (i <= r) {
			z[i] = min(z[i - l], r - i + 1);
		}
		while (i + z[i] < s.length()) {
			if (s[i + z[i]] == s[z[i]]) {
				z[i]++;
			} else {
				break;
			}
		}
		if (z[i] > 0 && i + z[i] - 1 > r) {
			l = i;
			r = i + z[i] - 1;
		}
	}

	return z;
}

int main() {
	string s;
	cin >> s;
	auto v = calc_z(s);
	for (vector<int>::iterator i = v.begin()+1; i != v.end(); ++i)
	{
		cout << *i << " ";
	}
	cout << "\n";
	return 0;
}
