import sys
from math import sqrt
input_data = sys.stdin.readlines()
del input_data[0]
input_data = [i.rstrip() for i in input_data]
for data in input_data:
	data = data.split()
	data = map(float,data)
	a,b,c,d = data
	s = (a+b+c+d)/2.0
	print sqrt((s-a)*(s-b)*(s-c)*(s-d))