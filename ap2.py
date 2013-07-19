def main():
	t = input()
	i = 0
	while  i < t:
		i += 1
		a3,al3,s = map(int,raw_input().split())
		n = s*2/(a3+al3)
		d = (2*a3-2*s/n)/(5-n)
		a1 = a3 - 2*d
		string = str(a1)
		print n
		for k in range(2,n+1):
			a = str(a1 + (k - 1)*d)
			string = string + " " + a
		if i == t:
			print string,
		else:
			print string


if __name__ == '__main__':
	main()