import sys
input_data = sys.stdin.readlines()
input_data = int(input_data[0].rstrip())
i = 1
ans = 0
while input_data/i - i + 1 >= 0:
	temp = input_data/i - i + 1
	ans += temp
	i += 1
print ans
