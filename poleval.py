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
	n = input()
	while n != -1:
		coff = map(int,raw_input().split())
		k = input()
		points = map(int,raw_input().split())
		for point in points:
			print point
			for i in range(0,n+1):
				powr[i] = power(point,i)
			ans = 0
			m = n
			for cof in coff:
				ans += cof*[m]
				m -= 1
		n = input()
if __name__ == '__main__':
	main()