def main():
	t = input()
	i = 0
	while i < t:
		i += 1
		string = raw_input()
		unique_string = set(string) - set(' ')
		if string == ' ':
			continue
		if len(string) == 1:
			d = ord(string) - ord('E')
			if d < 0:
				d = 26 + d
			value = ord(string) - d
			if value < 65:
				a = 65 - value
				value = 90 - a + 1
			print d,chr(value)
			continue

		if len(unique_string) == 0:
			print 'NOT POSSIBLE'
			continue
		lst = []
		for char in unique_string:
			lst.append((char,string.count(char)))
		lst.sort(key = lambda x: x[1])
		if lst[-1][1] == lst[-2][1]:
			print "NOT POSSIBLE"
		else:
			char = lst[-1][0]
			d = ord(char) - ord('E')
			if d < 0:
				d = 26 + d
			j = 0
			ans = ''
			while j < len(string):
				if string[j] != ' ':
					value = ord(string[j]) - d
					if value < 65:
						a = 65 - value
						value = 90 - a + 1
					ans += chr(value)
				else:
					ans += ' '
				j += 1 
			print d,ans


if __name__ == '__main__':
	main()