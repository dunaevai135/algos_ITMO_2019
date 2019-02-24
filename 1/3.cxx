#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <inttypes.h>

using namespace std;

int main () {
	ifstream fi;
	ofstream fo;
	size_t n;
	int tmp;
	vector<int> v;
	fi.open ("input.txt");
	fo.open ("output.txt");
	fi >> n;
	for (size_t i = 0; i < n; ++i)
	{
		fi >> tmp;
		v.push_back(tmp);
	}

	for (size_t i = 0; i < n; ++i)
	{
		auto lo = lower_bound(v.begin(), v.begin()+i, v[i]);
		long pos = lo - v.begin();
		v.insert(lo, v[i]);
		v.erase(v.begin() + i + 1);
		fo << pos + 1<< " ";// TODO magic const
	}

	fo << "\n";

	for (size_t i = 0; i < n; ++i)
	{
		fo << v[i] << " ";
	}

	fi.close();
	fo.close();
	return 0;
}