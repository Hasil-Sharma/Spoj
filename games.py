def gcd(a,b):
	if (a%b == 0):
		return b
	else:
		return gcd(b,a%b)

def main():
	t = input()
	i = 0
	while (i < t):
		avg = raw_input()
		try:
			dec =10**(len(avg) - avg.index('.') - 1)
			avg = int(''.join(avg.split('.')))
			k = gcd(avg,dec)
			print dec/k
		except:
			print 1
		i += 1

if __name__ == '__main__':
	main()
