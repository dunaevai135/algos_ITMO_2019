import random

fo= open("output.txt","w")
fi = open('input.txt', 'r')
n = int(fi.readline())
arr = [int(x) for x in fi.readline().split()]

isHeap = True
for i in range(1, n//2):
	if arr[i - 1] > arr[2 * i - 1] or arr[i - 1] > arr[2 * i]:
		isHeap = False
		break

if isHeap:
	fo.write("YES")
else:
	fo.write("NO")
