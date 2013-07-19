def power(base, exponent):
    exponent = bin(exponent)[2:][::-1]
 
    x = 1
    power = base 
    for i in range(0, len(exponent)):
        if exponent[i] == '1':
            x = (x * power)
        power = (power ** 2)
    return x


def main():
	n,k = map(int, raw_input().split())
	while (n != 0 and k != 0):
		a = 2*power(n-1,k,) + power(n,k) + 2*power(n-1,n-1) +  power(n,n)
		print a % 10000007
		n,k = map(int, raw_input().split())

if __name__ == '__main__':
	main()