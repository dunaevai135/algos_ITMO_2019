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

int main() {
	int N;
	cin >> N;
	string action;
	// string* array = new string[500000];//TODO N
	list<string> li;
	string key, val;
	unordered_map<string, list<string>::iterator> set;

	for (int i = 0; i < N; i++) {
		cin >> action;
		cin >> key;
		if (action == "get"){
			if (set.find(key) == set.end()) {
				cout << "<none>\n";
			}
			else {
				cout << *set[key] << "\n";
			}
		}
		else if (action == "prev" ) {
			if (set.find(key) == set.end() || set[key] == li.begin()) {
				cout << "<none>\n";
			}
			else {
				cout << *(prev(set[key])) << "\n";
			}
		}
		else if (action == "next") {
			if (set.find(key) == set.end() || next(set[key]) == li.end()) {
				cout << "<none>\n";
			}
			else {
				cout << *(next(set[key])) << "\n";
			}
		}
		else if (action == "put") {
			cin >> val;
			if (set.find(key) == set.end()) {
				li.push_back(val);
				set[key] = (--li.end());
			}
			else {
				(*set[key]) = val;
			}
		}
		else if (action == "delete") {
			if (set.find(key) == set.end()) {
			}
			else {
				auto it = set[key];
				set.erase(key);
				li.erase(it);
			}
		}
		else{
			cout << action << "\n";
		}
	}
	return 0;
}