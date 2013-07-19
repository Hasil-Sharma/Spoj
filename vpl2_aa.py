from math import log
def main():
	ti = input()
	j = 0
	while j < ti:
		j += 1
		p0,p1,t,p = map(int,raw_input().split())
		k = (log(p1) - log(p0))/t
		ans = (log(p) - log(p0))/k
		print "Scenario #%d: %.2f" % (j,ans)

if __name__ == '__main__':
	main()