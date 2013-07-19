import sys
input_data = sys.stdin.readlines()
input_data = [i.rstrip() for i in input_data]
del input_data[0]
for data in input_data:
	a,b,c = data.split()
	a,b = int(a), int(b)
	print a**2 -2*b