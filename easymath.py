def gcd(a,b):
	if a % b == 0:
		return b
	else:
		return gcd(b, a%b)


def main():
	t = input()
	i = 0
	while (i < t):
		i += 1
		n,m,a,d = map(int,raw_input().split())
		multiply = a*(a+d)*(a+2*d)*(a+3*d)*(a+4*d)
		lst = [a,a+d,a+2*d,a+3*d,a+4*d]
		count = 0
		while n <= m:
			if gcd(n,multiply) not in lst :
				count += 1
			n += 1
		print count

if __name__ == '__main__':
				main()			
