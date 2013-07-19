from math import acos,asin
def main():
	t = input()
	i = 0
	g = 9.806
	pi = 2*acos(0.0)
	while (i < t):
		i += 1
		r,v = map(int,raw_input().split())
		angle = r*g/pow(v,2)
		if angle > 1:
			ans = -1
		else:
			ans = round((asin(angle)/2)*(180/pi),2)
		string =  "Scenario #%d:" % (i)
		print string,ans
if __name__ == '__main__':
	main()