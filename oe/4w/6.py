from edx_io import edx_io

qu = []

with edx_io() as io:
	n = io.next_int()

	for x in range(0,n):
		sign = io.next_token()
		if sign == b'+':
			qu.append(qu.pop()+qu.pop())
		elif sign == b'-':
			qu.append(-qu.pop()+qu.pop())
		elif sign == b'*':
			qu.append(qu.pop()*qu.pop())
		else:
			qu.append(int(sign))

	io.writeln(qu.pop())
