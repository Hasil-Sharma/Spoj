import sys
input_data = sys.stdin.readlines()
del input_data[0]
for string in input_data:
	a,b = string.split()
	a,b = map(int,[a,b])
	print a*b