def main():
	t = input()
	i = 0
	while i < t:
		i += 1
		n = input()
		if n%2:
			print n/2 + 2
		else:
			print n/2 + 1

if __name__ == '__main__':
	main()