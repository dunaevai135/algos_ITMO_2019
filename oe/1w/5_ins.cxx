#include <stdlib.h>
#include <string.h>
#include <string>
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

    char buff[260000];
    long buff_index = 0;
    for (size_t i = 1; i < n; ++i) {
        int key = a[i];
        int j = i-1;
        char tmp[53];
        buff[0] = '\0';
        buff_index = 0;
        while (j >= 0 and a[j] > key) {
            a[j+1] = a[j];
            // strcpy(tmp, "Swap elements at indices " +itoa(j+1)+ " and " +itoa(j+2)+ ".\n");
            strcpy(buff+buff_index, "Swap elements at indices ");
            buff_index += strlen("Swap elements at indices ");
            strcpy(buff+buff_index, to_string(j+1).c_str());
            buff_index += to_string(j+1).length();
            strcpy(buff+buff_index, " and ");
            buff_index += strlen(" and ");
            strcpy(buff+buff_index, to_string(j+2).c_str());
            buff_index += to_string(j+2).length();
            strcpy(buff+buff_index, ".\n");
            buff_index += strlen(".\n");

            j--;
        }
        fo << buff;
        a[j+1] = key;
    }

    fo << "No more swaps needed." <<"\n";

    for (size_t i = 0; i < n; ++i)
    {
        fo << a[i] << " ";
    }

    fi.close();
    fo.close();
    return 0;
}