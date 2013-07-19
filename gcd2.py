def gcd(a,b):
	if b == 0:
		return a
	else:
		return gcd(b,a%b)

def main():
	t = int(input())
	i = 0
	while i < t:
		i += 1
		a,b = map(int,input().split())
		k = gcd(a,b)
		print (k)

if __name__ == '__main__':
	main()