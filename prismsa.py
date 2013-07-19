from math import sqrt
def main():
	t = input()
	i = 0
	while i < t:
		i += 1
		v = input()
		a_cube = 4*v
		print 6*sqrt(3)*v/pow(a_cube,1.0/3)
if __name__ == '__main__':
	main()