def main():
	t = input()
	i = 1
	while (i <= t):
		r = input()
		ans = 4*pow(r,2) + 0.25
		print "Case %d: %.2f" % (i,ans)
		i += 1	

if __name__ == '__main__':
	main()