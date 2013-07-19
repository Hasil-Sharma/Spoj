factors= {}
def prime_factors(n):
	"""Returns all the prime factors of a positive integer"""
	d = 2
	while n > 1:
		while n % d == 0:
			try:
				factors[d] += 1
			except:
				factors[d] = 1
			n /= d
		d = d + 1
	return factors

def main():
	n = input()
	for i in range(2,n+1):
		prime_factors(i)
	string = ''
	for num in factors.keys():
		string += str(num) + '^' + str(factors[num]) + ' * '
	print string.strip(' * ')

if __name__ == '__main__':
	main()
