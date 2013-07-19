dct = {0:0,1:1}
class memoize(dict):
	def __init__(self, func):
		self.func = func

	def __call__(self, *args):
		return self[args]

	def __missing__(self, key):
		result = self[key] = self.func(*key)
		return result
		
@memoize
def fib(n):
	if n == 0:
		return (0,1)
	else:
		a,b = fib(n//2)
		c = a*(2*b - a)
		d = b*b + a*a
		if n % 2 == 0 :
			return (c,d)
		else:
			return (d,c+d)

def main():
	t = input()
	i = 0
	while (i < t):
		i += 1
		n,m = map(int, raw_input().split())
		num = fib(n+2)[0]
		print (2*(num-1) - n) % m

if __name__ == '__main__':
	main()
