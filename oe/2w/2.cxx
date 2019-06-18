#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <inttypes.h>
#include <utility>

using namespace std;

bool sortbysec(const pair<int, char> &a, const pair<int, char> &b)
{
    return (a.second < b.second);
}

void countingSort(vector< pair <int, char> > &a)
{
    vector< pair <int, char> > output(a.size());
    vector<int> c(26, 0);

    for (auto &i : a) {
        c[i.second-'a'] += 1;
    }
    for (int i = 1; i < c.size(); ++i) {
        c[i] += c[i-1];
    }

    for (int i = a.size()-1; i >= 0; i--) {
        output[c[a[i].second-'a']-1] = pair <int, char> (a[i]);
        c[a[i].second-'a'] -= 1;
    }
    for (int j = 0; j < a.size(); ++j) {
        a[j] = output[j];
    }
//    copy(a.begin(), a.end(), back_inserter(output));
//    return output;
}

void countingSort2(vector< pair <int, char> > &arr){
    int count[26]={0};
    int i;
    vector< pair <int, char> > out(arr.size());


    for(i=0;i<arr.size();i++)
        ++count[arr[i].second-'a'];

    for(i=1;i<26;i++)
        count[i]+=count[i-1];



    for(i=arr.size()-1;i>=0;i--){
        out[count[arr[i].second-'a']-1]=arr[i];
        --count[arr[i].second-'a'];
    }

    for(i=0;i<arr.size();i++)
        arr[i]=out[i];
}

int main () {
    ifstream fi;
    ofstream fo;
    int m, n, k;
    fi.open ("input.txt");
    fo.open ("output.txt");
    fi >> n >> m >> k;
    vector<string> v(m);
    vector< pair <int, char> > vec(n);
    string tmp;
    for (size_t i = 0; i < m; ++i) {
        fi >> tmp;
        v[i] = tmp;
    }

    for (int i = 0; i < n; ++i)
    {
        vec[i] = make_pair(i, v[m-k][i]);
    }

    for (int j = 0; j < k; j++)
    {
        for (int i = 0; i < n; ++i)
        {
            vec[i].second = v[m-j-1][vec[i].first];
        }
       stable_sort(vec.begin(), vec.end(), sortbysec);
        // countingSort(vec);
    }

    for (size_t i = 0; i < n; ++i) {
        fo << vec[i].first + 1 << " ";
    }

    fo << "\n";
    fi.close();
    fo.close();
    return 0;
}