#include "edx-io.hpp"
using namespace std;

int main() {
	int N;
	io >> N;
	
	int* heap = new int[N];
	int head = 0;
	int tail = -1;
	int* array = new int[N];
	char action;
	int a, temp;

	for (int i = 0; i < N; i++) {
		io >> action;
		switch (action)
		{
		case 'A':
			io >> a;
			heap[++tail] = a;
			array[i] = a;
			siftdown(heap, tail, 0, tail-1);
			break;
		case 'X':
			if (head > tail) {
				io << '*' << '\n';
			}
			else {
				array[Queue[head].input_time] = tail;
				array[Queue[tail].input_time] = head;
				swop(&Queue[head], &Queue[tail]);
				io << Queue[tail--].value << '\n';
				heapifyDown(Queue, tail, array);
			}
			break;
		case 'D':
			io >> a;
			io >> temp;
			Queue[array[a - 1]].value = temp;
			heapifyUp(Queue, array[a - 1], array);
			break;
		default:
			break;
		}
	}
	return 0;
}