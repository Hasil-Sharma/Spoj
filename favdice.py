def main():
	t = input()
	i = 0
	while (i < t):
		i += 1
		ans = 0
		n = input()
		for k in range(1,n+1):
			ans += n/(1.0*k)
		print "%.2f" % (ans)

if __name__ == '__main__':
	main()