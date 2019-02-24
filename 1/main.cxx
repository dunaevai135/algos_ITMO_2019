#include <iostream>
#include <fstream>

using namespace std;

int main () {
	ifstream fi;
	ofstream fo;
	int a,b;
	fi.open ("input.txt");
	fo.open ("output.txt");
	fi >> a >> b;

	fo << a+b;

	fi.close();
	fo.close();
	return 0;
}