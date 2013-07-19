def modular_pow(base, exponent, modulus=10):
	result = 1
	while exponent > 0:
		if (exponent & 1) == 1:
		   result = (result * base) % modulus
		exponent = exponent >> 1
		base = (base * base) % modulus
	return result

def main():
	t = input()
	i = 0
	while (i < t):
		i += 1
		a,b = map(int, raw_input().split())
		print modular_pow(a,b)

if __name__ == '__main__':
	main()