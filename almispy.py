cdict = {1:5}
adict = {1:3}
def a(n):
	if n in adict:
		return adict[n]
	else:
		adict[n] = 3*a(n-1) + 2*c(n-1) + 1
		return adict[n]

def c(n):
	if n in cdict:
		return cdict[n]
	else:
		cdict[n] = 4*a(n-1) + 3*c(n-1) + 2
		return cdict[n]


def main():
	t = input()
	i = 0
	while i < t:
		i += 1
		n,m = map(int,raw_input().split())
		print a(n)%m,c(n)%m

if __name__ == '__main__':
	main()