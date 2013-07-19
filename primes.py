def pow(base, exponent, mod):
    """\
    Modular exponentiation through binary decomposition.
 
    We use the same technique as for the binary exponentiation above in
    order to find the modulo of our very large exponent and an arbitrary
    integer mod.
    """
    exponent = bin(exponent)[2:][::-1]
 
    x = 1
    power = base % mod
    for i in range(0, len(exponent)):
        if exponent[i] == '1':
            x = (x * power) % mod
        power = (power ** 2) % mod
    return x
import random
 
_mrpt_num_trials = 5 # number of bases to test
 
def is_probable_prime(n):
    assert n >= 2
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
        for i in range(s):
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
input_data = map(int,input_data)
t = (input_data[0])
index = 1
while index <= t :
	num = input_data[index]
	if is_probable_prime(num):
		print "YES"
	else:
		print "NO"
		
	index +=1
