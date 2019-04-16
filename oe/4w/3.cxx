#include <iostream>
#include <string>

using namespace std;

/**/	
#include "edx-io.hpp"
#define cin io
#define cout io
/**/

int check() {

	string cmd;
	long long *queue = new long long[10000];
	long index = 0;
	cin >> cmd;
	for (int j = 0; j < cmd.size(); j++) {
		switch (cmd[j])
		{
		case '(': case '[':
			queue[index++] = cmd[j];
			break;
		case ')': case ']':
			if (index <= 0 || queue[--index] != (cmd[j] == ')' ? '(' : '[')) {
				//cout << index << " " << queue[index] << " " << cmd[j] << " ";
				// cout << "NO\n";
				// goto end;
				return 1;
			}
			break;
		}
	}
	// cout << (index ? "NO\n" : "YES\n");
	// end:;
	return index;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << (check() ? "NO\n" : "YES\n");
	}
	return 0;
}
