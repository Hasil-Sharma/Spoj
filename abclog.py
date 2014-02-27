def main():
	while(True):
		n = input()
		if ( n == -1):
			break
		n = bin(n)
		n = n[2:]
		n = n[::-1]
		print int(n,2)
if __name__ == '__main__':
	main()