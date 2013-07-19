import math
cache = {}
def myfact(x):
	return cache.setdefault(x,math.factorial(x))
n,w,t,r = map(int,raw_input().split())
print (myfact(n)/(myfact(w)*myfact(t)*myfact(r))) % 1000000007