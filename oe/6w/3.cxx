#include <iostream>
#include <string>
#include <queue>
#include <deque>

/**/
#include "edx-io.hpp"
#define cout io
#define cin io
/**/

using namespace std;

struct t_node {
	int left, right;
} *tree;

int depth(int i) {
	int d = 1;
	if (tree[i].left) {
		d = max(depth(tree[i].left - 1) + 1, d);
	}
	if (tree[i].right) {
		d = max(depth(tree[i].right - 1) + 1, d);
	}
	return d;
}


int main() {
	int n, k, l, r;
	cin >> n;
	if (n) {
		tree = new t_node[n];
		for (int i = 0; i < n; ++i) {
			cin >> k >> tree[i].left >> tree[i].right;
		}
		cout << depth(0);
	}
	else {
		cout << 0;
	}
	return 0;
}
