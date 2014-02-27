def main():
	t = input()
	index = 0
	while(index < t):
		index += 1
		num = input()
		if(num%252 == 0 and num%525 == 0):
			print "Yes Yes"
		elif (num%252 != 0 and num%525 == 0):
			print "No Yes"
		elif (num%252 == 0 and num%525 != 0):
			print "Yes No"
		elif (num%252 != 0 and num%525 != 0):
			print "No No"
if __name__ == '__main__':
	main()