def fib(n):
	if n == 0:
		return (0, 1)
	else:
		a, b = fib(n // 2)
		c = a * (2 * b - a)
		d = b * b + a * a
		if n % 2 == 0:
			return (c, d)
		else:
			return (d, c + d)

def main():
	t = input()
	i = 0
	while (i < t):
		i += 1
		n = input()
		a,b = fib(n)
		vol = a*b-1
		print "%s%d" % ('$',vol % 1000000007)

if __name__ == '__main__':
	try:
		main()
	except:
		pass