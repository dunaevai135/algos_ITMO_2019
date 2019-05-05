// #include "edx-io.hpp"
#include <vector>
#include <algorithm>
using namespace std;

// #define cout io
// #define cin io

void heappush(vector<int> heap, int item){
    heap.push_back(item);
    siftdown(heap, 0, len(heap)-1)
}

int heappop(vector<int> heap){
    lastelt = heap.pop()    # raises appropriate IndexError if heap is empty
    if heap:
        returnitem = heap[0]
        heap[0] = lastelt
        siftup(heap, 0)
        return returnitem
    return lastelt
}

int main() {
	int N;
	cin >> N;
	
	vector<int> heap;
	v.reserve(1000000);
	int* array = new int[N];
	char action;
	int a, temp;

	for (int i = 0; i < N; i++) {
		cin >> action;
		switch (action)
		{
		case 'A':
			cin >> a;
			heappush(heap, a)
			array[i] = a;
			break;
		case 'X':
			if (head > tail) {
				cout << '*' << '\n';
			}
			else {
				pop = heappop(heap);
				cout << pop << '\n';
			}
			break;
		case 'D':
			cin >> a;
			cin >> newNum;
			oldNum = array[a-1];
            array[a-1] = newNum;
            int ind = find(heap.begin(), heap.end(), oldNum) - heap.begin();
            heap[ind] = newNum;
            siftdown(heap, 0, ind)
			break;
		default:
			break;
		}
	}
	return 0;
}