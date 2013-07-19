def main():
	t = input()
	i = 0
	while i < t:
		i += 1
		n = input()
		j = 0
		intime = []
		outtime = []
		while j < n:
			j += 1
			a,b = map(int,raw_input().split())
			intime.append(a)
			outtime.append(b)
		for incoming in intime:
			

if __name__ == '__main__':
	main()
