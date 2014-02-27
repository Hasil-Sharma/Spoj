def main():
	snum = raw_input()
	try:
		while snum:
			count = 0
			num = int(snum)
			for i in snum:
				try:
					if(num%int(i) == 0):
						count += 1
				except ZeroDivisionError:
					pass
			print count
			snum = raw_input()
	except EOFError:
		pass
if __name__ == '__main__':
	main()