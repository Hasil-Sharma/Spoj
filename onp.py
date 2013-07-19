def main():
	t = input()
	i = 0
	prec = {}
	prec['+'] = 1
	prec['-'] = 2
	prec['*'] = 3
	prec['/'] = 4
	prec['^'] = 5
	while i < t:
		i += 1
		string = raw_input()
		operators = []
		ans = ''
		for char in string:
			if char in 'abcdefghijklmnopqrstuvwxyz':
				ans += char
			elif char == '(':
				operators.append(char)
			elif char == ')':
				toptoken = operators.pop()
				while toptoken != '(':
					ans += toptoken
					toptoken = operators.pop()
			else:
				while len(operators) != 0 and prec[operators[-1]] >= prec[char]:
					chars = operators.pop()
					ans += chars
				operators.append(char)
		while not len(operators) == 0:
			char = operators.pop()
			ans += 
		print ans
if __name__ == '__main__':
	main()


