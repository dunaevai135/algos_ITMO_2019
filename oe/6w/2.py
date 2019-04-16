import bisect

fi = open('input.txt', 'r')
fo = open('output.txt', 'w')

[n, a] = fi.readline().split()
n = int(n)
a = float(a)
l = 0
r = a
h = [0,0,0]

while abs(r-l) > 0.000000000001:
    m = 1001
    h[0] = a
    h[1] = (r+l)/2
    # h[2] = 2*h[1]-h[0]+1

    for x in range(n-2):
        h[(x+2)%3] = 2*h[(x+1)%3]-h[x%3]+2
        if h[(x+2)%3] < m:
            m = h[(x+2)%3]
        if m < 0:
            break

    if m < 0:
        l = (r+l)/2
    else:
        r = (r+l)/2
    # print(m)

# print("asd")
h[0] = a
h[1] = (r+l)/2
for x in range(n-2):
    h[(x+2)%3] = 2*h[(x+1)%3]-h[x%3]+2
    # print(h[(x+2)%3])
fo.write(str(h[(n+2)%3]))