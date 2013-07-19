def main():
	t = input()
	i = 0
	while i < t:
		i += 1
		n = input()
		foxes = []
		for k in range(n):
			foxes.append(map(int,raw_input().split()))
		