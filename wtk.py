def f(n,k):
	if n == 1:
		return 1
	else:
		return ((f(n-1,k+1)+k)%n)+1

def main():
	t = input()
	i = 0
	while i < t:
		n = input()
		i += 1
		ans = f(n,1)
		print ans

if __name__ == '__main__':
	main()