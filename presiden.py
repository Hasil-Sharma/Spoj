def main():
	t = input()
	j = 0
	while j < t:
		j += 1
		c,v = map(int,raw_input().split())
		canditates = {}
		voters = []
		for i in range(1,v+1):
			if i <= c:
				canditates[i] = 0
			voters.append(map(int,raw_input().split()))
		for voter in voters:
			canditates[voter[0]] += 1
		sort = sorted(canditates,key = lambda x:canditates[x],reverse = True)
		if canditates[sort[0]] < v/2:
			for voter in voters:
				if voter.index(sort[0]) < voter.index(sort[1]):
					canditates[sort[0]] += 1
				else:
					canditates[sort[1]] += 1
			if canditates[sort[0]] > canditates[sort[1]]:
				print sort[0],2
			else:
				print sort[1],2
		else:
			print sort[0],1
if __name__ == '__main__':
	main()