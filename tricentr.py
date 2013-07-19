import sys
from math import sqrt

def find_side(area,x):
	return (2.0*area)/(3*x)

inpute = sys.stdin.readlines()
input_data = []
for i in inpute:
	input_data.append(i.strip('\n'))
n = int(input_data[0])
for i in xrange(1,n+1):
	data = input_data[i].split(' ')
	data =  map(float,data)
	a = data[0]
	gna = data[1]
	gnb = data[2]
	gnc = data[3]
	area = (3.0*gna*a)/2
	# print area
	b = find_side(area,gnb)
	c = find_side(area,gnc)
	r = (a*b*c)/(4*area)
	# print b
	# print c
	# print r
	hg = (2.0/3)*sqrt(abs(9*r*r-(a*a + b*b + c*c)))
	print round(area,3), round(hg,3)
