from math import sqrt
def main():
	t = input()
	while(t):
		t -= 1
		x,y,z = map(int,raw_input().split())
		a = y + 2*z
		b = -1*2*z*x
		c = -1*y*z*z
		t1 = (-1*b + sqrt(b*b - 4*a*c))/(2*a)
		if(t1%1 == 0): 
			print int(t1)
			continue
		t2 = (-1*b - sqrt(b*b - 4*a*c))/(2*a)
		if(t2%1 == 0): 
			print int(t2)
			continue
		print "Not this time"
if __name__ == '__main__':
	main()