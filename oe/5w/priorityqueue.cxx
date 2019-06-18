#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/**/
#include "edx-io.hpp"
#define cout io
#define cin io
/**/


void siftdown(vector<long long> &heap, long long startpos, long long pos) {
    long long newitem = heap[pos];
    while (pos > startpos) {
        long long parentpos = (pos - 1) / 2;
        long long parent = heap[parentpos];
        if (parent > newitem) {
            heap[pos] = parent;
            pos = parentpos;
            continue;
        }
        break;
    }
    heap[pos] = newitem;
}

void siftup(vector<long long> &heap, long long pos) {
    long long endpos = heap.size();
    long long startpos = pos;
    long long newitem = heap[pos];
    long long childpos = 2*pos + 1;
    while (childpos < endpos) {
        long long rightpos = childpos + 1;
        if ((rightpos < endpos) && !( heap[childpos] < heap[rightpos])) { //TODO
            childpos = rightpos;
            // cout << "A";
        }
        heap[pos] = heap[childpos];
        pos = childpos;
        childpos = 2*pos + 1;
    }
    heap[pos] = newitem;
    siftdown(heap, startpos, pos);
}

void heappush(vector<long long> &heap, long long item){
    heap.push_back(item);
    siftdown(heap, 0, heap.size()-1);
}

long long heappop(vector<long long> &heap){
    long long lastelt = heap.back();
    heap.pop_back();
    if (!heap.empty()) {
        long long returnitem = heap[0];
        heap[0] = lastelt;
        siftup(heap, 0);
        return returnitem;
    }
    return lastelt;
}

int main() {
    long long N;
    cin >> N;

    vector<long long> heap;
    heap.reserve(1000000);
    long long* array = new long long[N+1];
    char action;
    long long a;

    for (long long i = 0; i < N; i++) {
        cin >> action;
        switch (action)
        {
            case 'A':
                cin >> a;
                heappush(heap, a);
                array[i] = a;
                break;
            case 'X':
                if (heap.size() == 0) {
                    cout << '*' << '\n';
                }
                else {
                    long long pop = heappop(heap);
                    cout << pop << '\n';
                }
                break;
            case 'D':
                long long newNum;
                cin >> a;
                cin >> newNum;
                long long oldNum = array[a-1];
                array[a-1] = newNum;
                long long ind = find(heap.begin(), heap.end(), oldNum) - heap.begin();
                heap[ind] = newNum;
                siftdown(heap, 0, ind);
                // siftup(heap, 0);
                break;
        }
    }
    return 0;
}