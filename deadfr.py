from decimal import *
from fractions import gcd
def main():
	string = raw_input()
	while string!= '0':
		string = string.strip('...')
		rp = string[2:]
		string = Decimal(string)
		getcontext().prec = len(rp)
		nnum = Decimal(rp + '.' + rp)
		numer = nnum - string
		den = pow(10,len(rp))-1
		g = gcd(numer,den)
		if g==1 :
			print numer,'/',den
		else:
			print numer/g,'/',den/7
		string = raw_input()

if __name__ == '__main__':
	main()
