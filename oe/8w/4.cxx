#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <unordered_map>
#include <list>

using namespace std;
/**
#include "edx-io.hpp"
#define cout io
#define cin io
/**/
int hashOf(string s, uint32_t multiple) {
	int rv = 0;
	for (int i = 0; i < s.length(); ++i) {
		rv = multiple * rv + s[i];
	}
	return rv;
}
	  
int main() {
	ifstream fi;
	fi.open ("input.txt");
	FILE *fo = fopen("output.txt","wb");
	int N;
	fi >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i+1; ++j)
		{
			// cout << "\0" ;
			fprintf(fo, "%c", 0);
		}
		// cout << "\n" ;
		fprintf(fo, "\n");
	}
	return 0;
}