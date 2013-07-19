def main():
	n = input()
	if n == 10:
		print 2
	if n%10 == 0:
		print 2
	else:
		print 1
		print n%10

if __name__ == '__main__':
	main()