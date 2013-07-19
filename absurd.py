def main ():
	t = input()
	i = 0
	while i < t:
		i += 1
		c = int(raw_input().strip('0'))
		llimit = .95*c
		ulimit = 1.05*c
		e1 = c - (c%10)
		if e1 >= llimit and e1 <= ulimit:
			# print "e1",e1
			print "absurd"
			continue
		e2 = e1 + 5
		if e2 >= llimit and e2 <= ulimit and e2 != c:
			# print "e2",e2
			print "absurd"
			continue
		e3 = e2 + 5
		if e3 >= llimit and e3 <= ulimit and e3 != c:
			# print "e3",e3
			print "absurd"
			continue
		else:
			print "not absurd"

if __name__ == '__main__':
	main()
