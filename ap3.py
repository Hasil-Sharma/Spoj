from math import sqrt
def main():
	t = input()
	i = 0
	while i < t:
		i += 1
		an,al,sn = map(int,raw_input().split())
		a = an + al
		b = 5*al + 7*an + 2*sn
		c = 12*sn
		disc = int(sqrt(b**2 - 4*a*c))
		if (b + disc)%(2*a) == 0:
			ans = (b + disc)/(2*a)
			n = ans
			d = (al - an)/(n - 6)
			a = an - 2*d
			ans = [str(a+i*d) for i in range(n)]
			print n
			print ' '.join(ans)
if __name__ == '__main__':
	main()


