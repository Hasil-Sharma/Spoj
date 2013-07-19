from math import sqrt
def isfib(n):
	a = 5*(n<<1)
	if not sqrt(a+4)%1 or not sqrt(a-4)%1:
		return True
	else:
		return False

def cond(m):
	while not isfib(m):
			m -=1
	return m

def main():
	t = int(raw_input())
	i = 0
	phi = 1.618
	while i != t:
		ans = 0
		m = int(raw_input())
		mx = m
		tick = 0
		while tick != mx:
			k = cond(m)
			tick += k
			m  -= k
			ans += round(k*phi)
		i += 1
		print int(ans)
if __name__ == '__main__':
	main()