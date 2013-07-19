from decimal import Decimal
def main():
	t = input()
	i = 0
	while i < t:
		i += 1
		n = input()
		ans = 0
		for i in range(1,n+1):
			ans += Decimal(1.0)/Decimal(i)
		print round(ans,1)

if __name__ == '__main__':
	main()