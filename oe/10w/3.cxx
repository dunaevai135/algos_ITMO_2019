#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <list>

using namespace std;
/**
#include "edx-io.hpp"
#define cout io
#define cin io
/**/

string encode(string str) {
	string encoding = "";
	int count;

	for (int i = 0; str[i]; i++) {
		count = 1;
		while (str[i] == str[i + 1])
			count++, i++;
		encoding += to_string(count) + str[i];
	}

	return encoding;
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
