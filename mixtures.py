import difflib
def main():
	s1 = raw_input()
		s2 = raw_input()
	while s1 != '#':
		ans = 0
		for difference in difflib.ndiff(s1,s2):
			if difference[0] == '+':
				ans += 15
			elif difference[0] == '-':
				ans += 30
		print ans
		s1 = raw_input()
		s2 = raw_input()

if __name__ == '__main__':
	main()