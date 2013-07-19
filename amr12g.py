i = 0
t = input()
while i < t:
	i += 1
	n,m,k = map(int,raw_input().split())
	rows = []
	j = 0
	while j < n:
		rows.append(raw_input().count('*'))
		j += 1
	j = 0
	while j < k:
		j += 1
		rows = sorted(rows)
		rows[0] = m - rows[0]
	print sum(rows)