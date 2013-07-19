#from math import sqrt
#def is_prime(primes,n):
#	if n <= 1:
#		primes[n]=False
#		return None
#	if n == 2:
#		primes[n]=True
#		return None
#	if n % 2 == 0:
#		primes[n]= False
#		return None
#	sroot = int(sqrt(n) + 1)
#	i = 3
#	while i <=sroot:
#		if n % i == 0 :
#			primes[n]= False
#			return None
#		i += 2
#	return None
#def prime(primes,m,n):
#	for i  in xrange(m,n+1):
#		primes[i] = True
#	if m == 1:
#		primes[1] = False
#	if is_prime(primes,m):
#		for i in xrange(m, n+1):
#			if primes[i]:
#				for x in xrange(2*i, n+1, i):
#					primes[x] = False
#	
import random
 
_mrpt_num_trials = 5 # number of bases to test
def is_probable_prime(n):
    if n ==1 :
        return False
    # special case 2
    if n == 2:
        return True
    # ensure n is odd
    if n % 2 == 0:
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
        for i in xrange(s):
            if pow(a, 2**i * d, n) == n-1:
                return False
        return True # n is definitely composite
 
    for i in range(_mrpt_num_trials):
        a = random.randrange(2, n)
        if try_composite(a):
            return False
 
    return True # no base tested showed n as composite
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
	for val in xrange(m,n+1):
		if is_probable_prime(val):
			print val
	print '\n'
