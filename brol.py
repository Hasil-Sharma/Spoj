def main():
	p,b,r = map(int,raw_input().split())
	while p != 0:
		if p > r:
			ans = 0
			bets = [1*b,2*b,3*b]
			for bet in bets:
				while p > bet:
					p -= bet
					ans += 1
					if p == r:
						print ans
						break
					elif p < r:
						print "No accounting tablet"
						break
		elif p < r:
			ans = 0
			bets = [1*b,2*b,3*b]
			for bet in bets:
				while p - r > bet :
					p += bet
					ans += 1
					if p == r:
						print ans
						break
					elif p > r:
						print "No accounting tablet"	
						break

		p,b,r = map(int,raw_input().split())

if __name__ == '__main__':
	main()