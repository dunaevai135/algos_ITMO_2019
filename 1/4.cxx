#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
#include <inttypes.h>

using namespace std;

int main () {
    ifstream fi;
    ofstream fo;
    size_t n;
    double tmp;
    map <double, int> m;
    fi.open ("input.txt");
    fo.open ("output.txt");
    fi >> n;
    for (size_t i = 0; i < n; ++i)
    {
        fi >> tmp;
        m.emplace(tmp, i);
    }

    auto mid = m.begin();
    auto end = m.begin();
    advance(mid, n / 2);
    advance(end, n-1);

    fo << m.begin()->second+1 << " " << mid->second+1 << " " << end->second+1 <<"\n";


    fi.close();
    fo.close();
    return 0;
}