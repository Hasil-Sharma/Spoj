def main():
	t = input()
	while(t):
		t -= 1
		b,c,d = map(int,raw_input().split())
		a = (pow(c-d,2) - pow(c - b,2))/(d-b)
		if a < 0:
			a = -1*a
		print a
if __name__ == '__main__':
	main()