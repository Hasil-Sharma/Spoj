import sys
input_data = sys.stdin.readlines()
t = int(input_data[0])
i = 1
while i <= t:
	l,n = map(int,input_data[i].split())
	attack = {}
	for i in range(l+1):
		attack[i] = 0
	for i in range(n):
		c,r,d = map(int,input_data.pop(0).split())
		la = c - r
		if la < 1:
			la = 1
		ua = c + r
		if ua > l:
			ua = l
		for k in range(la,ua+1):
			attack[k] += d
	m = int(input_data.pop(0))

	for i in range(m):
		hp = int(input_data.pop(0))
		pos = 1
		for i in range(1,l+1):
			pos += 1
			hp = hp - attack[pos - 1]
			if hp <= 0 :
				print pos - 1
				break
		if hp > 0 :
			print "Bloon leakage"



