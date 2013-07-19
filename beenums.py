from math import sqrt
def main():
	n = input()
	while n != -1:
		disc = sqrt(1+4*(n-1)/3)
		print disc
		if disc % 2 == 1:
			print "Y"
		else:
			print "N"
		n = input()

if __name__ == '__main__':
	main()