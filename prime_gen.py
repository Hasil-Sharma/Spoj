import random
 
_mrpt_num_trials = 5 # number of bases to test
 
def is_probable_prime(n):
	# special case 2
	if n == 2:
		return True
	# ensure n is odd
	if n % 2 == 0 or n == 1:
		return False
	# write n-1 as 2**s * d
	# repeatedly try to divide n-1 by 2
	s = 0
	d = n-1
	while True:
		quotient, remainder = divmod(d, 2)
		if remainder == 1:
			break
		s += 1
		d = quotient
	assert(2**s * d == n-1)
 
	# test the base a to see whether it is a witness for the compositeness of n
	def try_composite(a):
		if pow(a, d, n) == 1:
			return False
		for i in range(s):
			if pow(a, 2**i * d, n) == n-1:
				return False
		return True # n is definitely composite
 
	for i in range(_mrpt_num_trials):
		a = random.randrange(2, n)
		if try_composite(a):
			return False
 
	return True # no base tested showed n as composite
def prime_finder(m,n):
	prime_dict = {}
    a = range(m,n+1)
	for num in a:
		prime_dict[num] = True
    
	for num in a:
		if  is_probable_prime(num):
			for element in xrange(2*num,n+1,num):
				del prime_dict[element]
                del 
		else:
				for element in xrange(num,n+1,num):
					del prime_dict[element]
	return prime_dict
import sys
input_data = sys.stdin.read()
input_data = input_data.split('\n')
input_data.remove('')
input_data[0] = int(input_data[0])
index = 1
while index <= input_data[0] :
	a = input_data[index].split(' ')
	a = map(int,a)
	m = a[0]
	n = a[1]
	index = index +1
	prime_dict = prime_finder(m,n)
	for elements in xrange(m,n+1):
			print elements
	print '\n'
