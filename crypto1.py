def Power(base, exponent, mod):
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
import time
import math
import datetime
import sys
input_data = sys.stdin.read()
input_data = input_data.split('\n')
input_data.remove('')
a = int(input_data[0])
p = 4000000007
k = 1000000001
x1 = Power(a,(k+1),p)
x2 = p - x1
for seconds_to_attack in [x1,x2]:
	if time.localtime(seconds_to_attack).tm_year < 2030:
		print time.strftime("%a %b %d %H:%M:%S %Y", time.localtime(seconds_to_attack))
#print datetime.datetime.fromtimestamp(seconds_to_attack)

