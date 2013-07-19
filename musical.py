def josephus(n, k):
   r = 0
   i = 2
   while i <= n:
     r = (r + k) % i;
     i+= 1
   return r+1
import sys
input_data = sys.stdin.readlines()
del input_data[-1]
for data in input_data:
	try:
		n,d =map(int,data.split())
		ans = josephus(n,d)
		print str(n)+" "+str(d)+" "+str(ans)
	except:
		pass

