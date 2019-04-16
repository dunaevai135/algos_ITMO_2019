#include <iostream>
#include <string>
#include <queue>
#include <set>

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
    queue<long long> q;
    multiset<long long> s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> cmd;
        switch (cmd)
        {
            case '+':
                cin >> t;
                q.push(t);
                s.insert(t);
                break;
            case '-':
                s.erase(s.find(q.front()));
                q.pop();
                break;
            case '?':
                cout << *s.begin() << "\n";
                break;
        }
    }
    return 0;
}