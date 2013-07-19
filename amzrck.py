dct = {0:1,1:2}

def fib(n):
	if n in dct:
		return dct[n]
	else:
		dct[n] = fib(n-1) + fib(n-2)
		return dct[n]

def main():
	t = input()
	i = 0
	while i < t:
		i += 1
		n = input()
		print fib(n)

if __name__ == '__main__':
	main()