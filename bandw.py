def main():
	a,t = raw_input().split()
	maxval = len(a)
	i = 1
	if a[0] == a[1]:
		count = 0
	else:
		count = 1
	while i < maxval:
		if a[i] = 