import bisect

fi = open('input.txt', 'r')
fo = open('output.txt', 'w')

n = fi.readline()
arr = [int(x) for x in fi.readline().split()]
m = fi.readline()

for x in list(map(int, fi.readline().split())):
    l = bisect.bisect_left(arr, x)
    if l >= len(arr) or arr[l] != x:
        fo.write('-1 -1\n')
    else:
        fo.write(f'{l + 1} {bisect.bisect_right(arr, x)}\n')

