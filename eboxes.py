def main():
	i = 0
	t = input()
	while (i < t):
		i += 1
		n,k,T,f = raw_input().split()
		n,k,f = map(int,[n,k,f])
		print n + k*(f-n)/(k-1)

if __name__ == '__main__':
	main()