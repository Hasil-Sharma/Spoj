import sys
input_data = sys.stdin.readlines()
del input_data[-1]
input_data = [i.rstrip('Q\n') for i in input_data]
for string in input_data:
	coordinates = [(0,0)]
	tmp = (0,0)
	ans = 0
	for s in string:
		if s == 'U':
			tmp = (tmp[0],tmp[1]+1)
			if tmp in coordinates:
				ans += 1
			else:
				coordinates.append(tmp)
		elif s == 'D':
			tmp = (tmp[0],tmp[1]-1)
			if tmp in coordinates:
				ans += 1
			else:
				coordinates.append(tmp)
		elif s == 'L':
			tmp = (tmp[0] - 1,tmp[1])
			if tmp in coordinates:
				ans += 1
			else:
				coordinates.append(tmp)
		elif s == 'R':
			tmp = (tmp[0] + 1,tmp[1])
			if tmp in coordinates:
				ans += 1
			else:
				coordinates.append(tmp)
	print ans


