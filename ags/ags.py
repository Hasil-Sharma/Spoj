def main():
	t = input()
	while t:
		t -= 1
		a,d,r = map(int,raw_input().split())
		n,mod = map(int,raw_input().split())
		ans = a%mod
		#print "Value of n:",n
		for j in range(2,n+1):
			if j%2 == 1:
				ans = (ans*(r%mod))%mod
			else:
				ans = ((ans%mod) + (d%mod))%mod
		print ans%mod


if __name__ == '__main__':
	main()