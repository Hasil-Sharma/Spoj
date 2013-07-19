def gcd(a,b):
	if a%b == 0 :
		return b
	else:
		return gcd(b,a%b)
def main():
	t = input()
	i = 0
	while  i < t:
		i += 1
		s1,s2 = map(int,raw_input().split())
		g = gcd(abs(s1),abs(s2))
		s1 = s1/g
		s2 = s2/g
		print abs(s1-s2)
if __name__ == '__main__':
	main()