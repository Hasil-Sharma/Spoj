def gcd(a,b):
	if not a % b:
		return b
	else:
		return gcd(b,a%b)


def main():
	t = input()
	i = 0
	while i < t:
		n,m = map(int, raw_input().split())
		count = 0
		lst = range(1,m+1)
		for k in lst:
			if gcd(n,k) == 1:
				pass
			else:
				for j in lst:
					if j%k == 0:
						lst.remove(j)
		for k in lst:
			if gcd(n,k) == 1:
				pass
			else:
				for j in lst:
					if j%k == 0:
						lst.remove(j)
		print len(lst)
		i += 1

if __name__ == '__main__':
	main()