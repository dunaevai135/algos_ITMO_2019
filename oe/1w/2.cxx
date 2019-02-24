#include <iostream>
#include <fstream>
#include <inttypes.h>

using namespace std;

int main () {
	ifstream fi;
	ofstream fo;
	int64_t a,b;
	fi.open ("input.txt");
	fo.open ("output.txt");
	fi >> a >> b;

	fo << a+b*b;

	fi.close();
	fo.close();
	return 0;
}