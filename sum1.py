import sys
def sol(k,n):
	n = (n-1)/k
	return k*n*(n+1)/2
	
input_data = sys.stdin.readlines()
t = int(input_data[0])
k = 1
while k <= t:
	num = int(input_data[k])
	k += 1
	ans = sol(3,num) + sol(5,num) - sol(15,num)
	print ans