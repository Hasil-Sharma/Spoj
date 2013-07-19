import sys
num = sys.stdin.readlines()
ans = 0
i = 0
while i < 10:
	if ans < 100 :
		temp = ans
		ans += int(num[i])
		i += 1
	elif ans > 100 and (100 - temp) >= (ans - 100):
		print ans
		break
	elif ans > 100 and (100 - temp) < (ans - 100):
		print temp
		break
if ans <= 100:
	print ans