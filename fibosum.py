def multiply(f,m):
	x =  f[0][0]*m[0][0] + f[0][1]*m[1][0]
	y =  f[0][0]*m[0][1] + f[0][1]*m[1][1]
	z =  f[1][0]*m[0][0] + f[1][1]*m[1][0]
	w =  f[1][0]*m[0][1] + f[1][1]*m[1][1]

	f[0][0] = x
	f[0][1] = y
	f[1][0] = z
	f[1][1] = w

def power(f,n):
	if n == 0 or n == 1:
		return None
	m = [[1,1],[1,0]]
	power(f,n/2)
	multiply(f,f)
	if n%2 != 0:
		multiply(f,m)

def fib(n,dictionary):
	f = [[1,1],[1,0]]
	if n == 0:
		return 0
	elif n in dictionary:
		return dictionary[n]
	else:
		power(f, n - 1)
		dictionary[n] = f[0][0]
		dictionary[n-1] = f[0][1]
		dictionary[n-2] = f[1][1]
		return dictionary[n]

import sys
import math
input_data =  sys.stdin.readlines()
dictionary={0:0,1:1}
del input_data[0]
input_data = [i.rstrip() for i in input_data]
for data in input_data:
	try:
		data = data.split()
		a,b = map(int,data)
		ans = -fib(a+2,dictionary) + fib(a,dictionary) + fib(b+2,dictionary)
		print ans % 1000000007
	except:
		break