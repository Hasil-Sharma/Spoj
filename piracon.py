import sys
input_data = sys.stdin.readlines()
t = int(input_data[0])
i = 1
while i <= t:
	n = int(input_data[i])
	tri = 2*n*(n-1)
	total = n*(2*n+1)*(n+1)/3 - pow(n,2) + tri
	print "Pyramid E. Nro# "+str(i)+": "+str(total)
	print "Tringus:",tri
	i += 1