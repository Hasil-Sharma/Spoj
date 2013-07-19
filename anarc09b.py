import sys
input_data =  sys.stdin.readlines()
del input_data[-1]
input_data = [i.rstrip() for i in input_data]
for data in input_data:
	a,b = map(int,data.split())
	if a%b == 0 or b%a == 0:
		print max(a,b)/min(a,b)
	else:
		print a*b