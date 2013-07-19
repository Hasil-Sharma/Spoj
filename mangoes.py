import sys
input_data = sys.stdin.readlines()
del input_data[0]
for n in input_data:
	try:
		n = int(n)
		if n % 2 == 0:
			print pow((n/2 - 1),2)%n
		else:
			print pow(((n+1)/2 - 1),2)%n
	except:
		pass