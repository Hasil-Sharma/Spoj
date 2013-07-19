def main():
	t = input()
	i = 0
	while ( i < t):
		i += 1
		ans = 1
		num = raw_input()
		j = 0
		while j < len(num)-1:
			n = 1
			while j+1 < len(num) and num[j] == num[j+1]:
				n += 1
				j += 1
			j += 1
			ans *= pow(2,n-1)
		print ans 

if __name__ == '__main__':
	try:
		main()
	except:
		pass
