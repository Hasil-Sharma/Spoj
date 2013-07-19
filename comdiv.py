from fractions import gcd
import sys
import math
input_data = sys.stdin.readlines()
del input_data[0]
for i in input_data:
	i = i.rstrip()
	a,b = i.split()
	g = gcd(int(a),int(b))
	sqt = math.sqrt(g)
	ans = 0
	i = 1
	while i <= sqt:
		if g % i == 0:
			ans += 2
			if i == g/i:
				ans = ans - 1
		i += 1
	print ans