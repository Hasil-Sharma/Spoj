from math import sqrt
def find_fraction(n):
	d = int(-1 + sqrt(1 + 8*n))/2
	e = int(n - d*(d+1)/2)
	if e<= 1:
		v1,v2 = d + e,1
	else:
		v1,v2 = d-e+2,e
	if d % 2 == 0:
		string = str(v1) + '/'+ str(v2)
	else:
		string = str(v2) + '/'+ str(v1)
	return string
import sys
input_Data = sys.stdin.read()
input_Data = input_Data.split("\n")
input_Data.remove("")
input_Data = map(int,input_Data)
index = 0
t = input_Data[index]
while index < t:
	index += 1
	num = input_Data[index]
	ans = find_fraction(num)
	print "TERM " + str(num) + " IS " + ans 
