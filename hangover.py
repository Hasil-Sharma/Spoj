import sys
input_data = sys.stdin.readlines()
del input_data[-1]
for num in input_data:
	num = float(num)
	ans = 0
	i = 2.0
	while num >= ans:
		ans += 1/i
		i += 1
	print int(i-2), "card(s)"

            