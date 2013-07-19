dct = {0:1,1:1}
def fact(n):
	if n in dct:
		return dct[n]
	else:
		dct[n] = n*fact(n-1)
		return dct[n]


def main():
	try:
		while True:
			n,k = map(int,raw_input().split())
			ns = map(int,raw_input().split())
			ans = fact(n)
			for i in ns:
				ans = ans/fact(i)
			print ans
	except:
		pass

if __name__ == '__main__':
	main()
