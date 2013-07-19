''' 
To find a(n) % mod = (a*r^((n-1)/2) + d*(1+r+r^2...+r^((n-1)/2)))%mod = ( a*r^((n-1)/2)%mod + d*(1+r+r^2+...+r^((n-1)/2))%mod )%mod
					value1 = a*r^((n-1)/2)
					value2 = d*(1+r+r^2+...+r^((n-1)/2))
					a(n) % mod = (value1 + value2) % mod = (value1 % mod + value2 % mod ) % mod
					x = (n-1)/2
					value1 % mod = (a*r^((n-1)/2)) % mod = ( a % mod * r^x % mod ) % mod
					value2 % mod = (d*(1+r+r^2+...+r^x)) % mod = ( d % mod * (1 + r + r^2 + .. + r^x) % mod) % mod
					a(n) % mod = ( ( a % mod * r^x % mod ) % mod + ( d % mod * (1 + r + r^2 + .. + r^x) % mod) % mod ) % mod
					(1 + r + r^2 + .. + r^x) % mod = ( 1 % mod + r % mod + r^2 % mod + .. + r^x % mod) % mod
					a(n) % mod = ( ( a % mod * r^x % mod ) % mod + ( d % mod * ( 1 % mod + r % mod + r^2 % mod + .. + r^x % mod) % mod ) % mod
'''
dct = {}

def modular_pow(base,exponent,modulus):
	if exponent in dct:
		return dct[exponent]
	else:
		c = 1
		for e_prime in range(1,exponent + 1):
			c = (c*base) % modulus
			dct[e_prime] = c
		return c

def main():
	t = input()
	i = 0
	while i < t:
		i += 1
		a,d,r = map(int,raw_input().split())
		n,mod = map(int,raw_input().split())
		x = (n-1)/2
		ans = ((a % mod) * modular_pow(r,x,mod)) % mod
		value = 0
		j = 0
		while j <= x:
			value += modular_pow(r,j,mod)
			j+=1
		value =((d % mod) * (value % mod)) % mod
		if n % 2 == 0:
			ans = (ans + value) % mod
		else:
			ans = (ans + value - d%mod)%mod

		print ans

if __name__ == '__main__':
	main()