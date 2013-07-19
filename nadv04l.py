from math import floor

def main():
	t = input()
	i = 0
	phi = 1.61803398874989484820458
	while i != t:
		m = input()
		ans = int((m*phi + 2 - phi))
		i += 1
		print ans
if __name__ == '__main__':
	main()