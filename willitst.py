def main():
	n = bin(input())
	n = set(n[3:])
	if len(n) == 1 and n.pop() == '0':
		print "TAK"
	else:
		print "NIE"

if __name__ == '__main__':
	main()
