import re

fo= open("output.txt","w")
fi = open('input.txt', 'r')

sub = fi.readline().strip()
string = fi.readline().strip()

ans = [m.start(0) + 1 for m in re.finditer('(?='+sub+')', string)]

fo.write(str(len(ans)) + '\n')
fo.write(' '.join(str(r) for r in ans))
