try:
	import sys
	from math import sqrt
	input_data = sys.stdin.readlines()
	input_data = [i.rstrip() for i in input_data]
	i = 0 
	j = int(input_data[0])
	while i < j:
		input_data.remove('')
		i += 1
	print input_data
	j = 2*j
	i = 1
	while i <= j:
		alfa,beta = map(float, input_data[i].split())
		p,q,r = map(float, input_data[i+1].split())
		print alfa,beta
		print p,q,r
		i += 2
		a = pow(p-alfa,2) - pow(r,2)
		b = 2*(beta*p - p*q + alfa*beta + q*alfa)
		c = pow(q-beta,2) - pow(r,2)
		dis = sqrt(pow(b,2) - 4*a*c)
		m1 = (-b + dis)/(2.0*a)
		c1 = beta - m1*alfa
		y1 = m1*52.5 + c1
		m2 = (-b - dis)/(2.0*a)
		c2 = beta - m2*alfa
		y2 = m2*52.5 + c2
		if ( y1 > -3.66 and y1 < 3.66) or ( y2 > -3.66 and y2 < 3.66):
			print "Goal!"
		else:
			print "No goal..."

except:
	pass