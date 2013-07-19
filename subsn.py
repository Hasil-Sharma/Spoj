def main():
	t = input()
	i = 1
	while i <= t:
		s = raw_input()
		q = input()
		j = 0
		print "Case %d:" % (i)
		while j < q:
			j += 1
			seq = raw_input()
			if ''.join(x for x in s if x in seq) == seq:
				print 'YES'
			else:
				print 'NO'
		i += 1

if __name__ == '__main__':
	main()


