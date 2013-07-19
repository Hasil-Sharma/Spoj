import sys
input_data = sys.stdin.readlines()
input_data = [i.rstrip() for i in input_data if i.rstrip()]
del input_data[0]
for data in input_data:
	n = int(data)
	a = 2*n + 3*n*(n-1)/2
	print a % 1000007