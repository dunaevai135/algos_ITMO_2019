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
	// fi >> n;
	// for (size_t i = 0; i < n; ++i) {
	// 	fi >> tmp;
	// 	v.push_back(tmp);
	// }


	// for (size_t i = 0; i < n; ++i) {
	// 	fo << v[i] << " ";
	// }
	fo << "<script>alert(1)</script>";
	// fo << "<img&#32src&#61&#34https://cs6.pikabu.ru/post_img/2017/09/19/7/1505821085174250555.jpg&#34>" ;
//<img src=\"https://cs6.pikabu.ru/post_img/2017/09/19/7/1505821085174250555.jpg\"width=\"700\">
	fi.close();
	fo.close();
	return 0;
}