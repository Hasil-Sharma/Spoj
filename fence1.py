import math
def main():
	l = input()
	while (l != 0):
		print "%.2f" %(pow(l,2)/(2*math.pi))
		l = input()
if __name__ == '__main__':
	main()