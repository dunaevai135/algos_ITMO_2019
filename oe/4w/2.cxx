#include <iostream>
#include <string>

using namespace std;

/**/
#include "edx-io.hpp"
#define cin io
#define cout io
/**/

int main() {
	int n;
	long long t;
	char cmd;
	long long *stack = new long long[1000000]();
	long long lindex = 0;
	long long rindex = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> cmd;
		if (cmd == '+') {
			cin >> stack[rindex++];
		}
		else {
			cout << stack[lindex++] << '\n';
		}
	}

	return 0;
}