import sys
input_data = sys.stdin.readlines()
del input_data[-1]
input_data = [i.rstrip() for i in input_data]
input_data = map(int,input_data)
num = {i : 2**i for i in xrange(1,16)}
for data in input_data:
	if data == 1:
		print 0
		continue
	for i in xrange(1,15):
		if data >= num[i] and data < num[i+1]:
			print i