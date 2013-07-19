import sys
input_data = sys.stdin.readlines()
del input_data[-1]
try:
	for data in input_data:
		data = data.split()
		e,f,s,m,ed,fd,sd,md = map(int,data)
		x = 0
		while True:
			if ((e+x)%ed == 0):
				y = fd*(e+x)/ed - f;
				z = sd*(e+x)/ed - s;
				w = md*(e+x)/ed - m;
				if(x>=0 and y>=0 and w>=0 and z>=0):
					break
			x += 1
		print x,y,z,w
except:
	pass

