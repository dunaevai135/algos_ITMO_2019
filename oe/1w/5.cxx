#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
#include <inttypes.h>

using namespace std;

ifstream fi;
ofstream fo;

void quickSortR(long *a, long l, long r) {
    long s = l;
    long n = r;
    if (r-l < 1 )
        return;
    long temp, p;

    p = a[ (r+l)/2 ];

    do {
        while ( a[l] < p ) l++;
        while ( a[r] > p ) r--;

        if (l < r) {
            temp = a[l]; a[l] = a[r]; a[r] = temp;
            fo << "Swap elements at indices " << l+1 << " and " << r+1 << ".\n";
        }
        if (l <= r) {
            l++; r--;
        }
    } while ( l<=r );

    quickSortR(a, s, r);
    quickSortR(a, l, n);
}

int main () {
    size_t n;
    long a[5000];
    fi.open ("input.txt");
    fo.open ("output.txt");
    fi >> n;
    for (size_t i = 0; i < n; ++i)
    {
        fi >> a[i];
    }

    quickSortR(a, 0, n-1);

    fo << "No more swaps needed." <<"\n";

    for (size_t i = 0; i < n; ++i)
    {
        fo << a[i] << " ";
    }

    fi.close();
    fo.close();
    return 0;
}