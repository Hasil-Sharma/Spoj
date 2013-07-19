from math import sqrt
def main():
	t = input()
	i = 0 
	while (i < t):
		i += 1
		r = input()
		print "%0.4f" % round(8*(2-sqrt(2))*pow(r,3),4)

if __name__ == '__main__':
	main()