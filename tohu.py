def main():
	t = input()
	i = 0
	while i < t:
		i += 1
		n = input()
		if n == 1:
			print "%.11f" % (2/3.0)
		else:
			ans = 3.0/4-1/(2.0*(n+1)*(n+2))
			print "%.11f" % (ans)

if __name__ == '__main__':
	main()