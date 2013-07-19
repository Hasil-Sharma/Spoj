from math import sqrt

def dist(a,b,c,p,q,r):
	return abs(1.0*(a*p + b*q -c))/sqrt(a**2+b**2)

def main():
	t = input()
	i = 0
	while (i < t):
		i += 1
		blank = raw_input()
		alfa,beta = map(float,raw_input().split(' '))
		p,q,r = map(float,raw_input().split(' '))
		a = 3.66 - beta
		b = alfa - 52.5
		c = 3.66*alfa - 52.5*beta
		_b = 52.5 + alfa
		_c = 3.66*alfa + 52.5*beta
		if dist(a,b,c,p,q,r) > r or dist(a,_b,_c,p,q,r) > r:
			print "Goal!"
		else:
			print "No goal..."

if __name__ == '__main__':
	main()