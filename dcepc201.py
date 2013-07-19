def main():
	t = input()
	i = 0
	while (i < t):
		i += 1
		lst = raw_input().split()
		string = ''.join(lst)
		chars = set(string)
		dct = {}
		odct = {}
		for stg in lst:
			dct[stg] = {}
			for char in chars:
				dct[stg][char] = stg.count(char)
				try:
					odct[char] += stg.count(char)
				except:
					odct[char] = stg.count(char)
			mchar = max(odct, key = lambda x: odct[x])
		print "Case #%d:"%(i)
		for stg in lst:
			dct[stg] = sorted(dct[stg], key = lambda x: dct[stg][x])
			
			

if __name__ == '__main__':
	main()	