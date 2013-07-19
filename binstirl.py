def strl(n,m):
	if n == 0 and m == 0:
		return 1
	elif (m == 0 and n > 0) or (n == 0 and m > 0) :
		return 0
	elif m > 0 and n >0:
		return m*strl(n-1,m) + strl(n-1,m-1)

import sys
input_data = sys.stdin.readlines()
del input_data[0]
for data in input_data:
	try:
		data = data.rstrip()
		n,m = map(int,data.split())
		ans = strl(n,m)
		print ans % 2
	except:
		pass