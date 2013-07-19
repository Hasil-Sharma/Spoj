import sys
input_data = sys.stdin.readlines()
input_data = [i.rstrip() for i in input_data if i.rstrip()]
del input_data[0]
dct = {'h': None,'a': None,'e': None}
for data in input_data:
	H,A = map(int,data.split())
	dct['e'] = 'air'
	time = 0
	while True:
		if dct['e'] == 'air':
			H += 3
			A += 2
			time += 1
			if H > 20 and A <= 10:
				dct['e'] = 'fire'
			elif H > 5 and A > 10:
				dct['e'] = 'water'
			else:
				break

		elif dct['e'] == 'fire':
			H -= 20
			A += 5
			if H <= 0 or A <= 0:
				break
			time += 1
			dct['e'] = 'air'

		elif dct['e'] == "water":
			H -= 5
			A -= 10
			if H <= 0 or A <= 0:
				break
			time += 1
			dct['e'] = 'air'
	print time



