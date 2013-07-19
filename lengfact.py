from math import log
pi= 3.14159265358979323 
e =2.71828182845904523536 
def main():
	t = input()
	i = 0 
	while (i < t):
		i += 1
		n = input()
		print int((log(2*pi*n,e)/2 + n*(log(n,e) - 1))/log(10,e)) + 1

if __name__ == '__main__':
	main()