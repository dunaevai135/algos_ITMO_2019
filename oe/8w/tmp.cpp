#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;
/**
#include "edx-io.hpp"
#define cout io
#define cin io
/**/

int main() {
	int N;
	cin >> N;
	char action;
	long long key, temp;
	unordered_set<long long> set;

	for (int i = 0; i < N; i++) {
		cin >> action;
		cin >> key;
		switch (action)
		{
		case 'A':
			set.insert(key);
			break;
		case 'D':
			set.erase(key);
			break;
		case '?':
			if (set.find(key) == set.end()) 
					cout << "N\n"; 
				else
					cout << "Y\n"; 
			break;
		default:
			break;
		}
	}
	return 0;
}