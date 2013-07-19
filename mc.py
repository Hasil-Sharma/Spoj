import difflib
def maind():
	print __name__
	s1 = raw_input()
	s2 = raw_input()
	while True:
		ans = 0
		for difference in difflib.ndiff(s1,s2):
			if difference[0] == '+':
				ans += 30
			elif difference[0] == '-':
				ans += 15
		print ans
		s1 = raw_input()
		if s1 == '#':
			break
		s2 = raw_input()

if __name__ == '__main__':
	maind()