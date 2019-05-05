#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <list>
#include <map>

using namespace std;
/**
#include "edx-io.hpp"
#define cout io
#define cin io
/**/

long long calc_distance(vector<long> pos) {
	long long sum = 0;
	long long temp;
	long k = pos.size() - 1;
	for (long i = pos.size() - 1; i >= 0; i--) {
		temp = (long long)k * pos[i];
		sum += temp -1 - i;
		k -= 2;
	}
	// for (long i = 1; i < pos.size(); i++)
	// {
	// 	sum -= i;
	// }
	return sum;
}

int main() {
	ifstream fi("input.txt");
	ofstream fo("output.txt");

	string st = "";
	string tmp;
	while (!fi.eof()) {
		fi >> tmp;
		if (tmp != "") {
			st += tmp;
		}
		tmp = "";
	}
	long long ans = 0;
	map<char, vector<long>> lett;
	for (long i = 0; i < st.length(); i++) {
		lett[st[i]].push_back(i);
	}

	for (char i = 'a'; i <= 'z'; i++) {
		if (lett.count(i) && lett[i].size() > 1) {
			counter += calculate_sum_distance(lett[i]);
		}
	}

	fo << ans;
	fo << "\n";
	return 0;
}