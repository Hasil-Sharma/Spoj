nums = [2, 4, 9, 16, 25, 64, 289, 729, 1681, 2401, 3481, 4096, 5041, 7921, 10201, 15625, 17161, 27889, 28561, 29929, 65536, 83521, 85849, 146689, 262144, 279841, 458329, 491401, 531441, 552049, 579121, 597529, 683929, 703921, 707281, 734449, 829921]
import sys
input_data = sys.stdin.readlines()
t = input_data.pop(0)
while input_data:
	a,b = map(int,input_data.pop(0).split())
	ans = 0
	for i in nums:
		if i >= a and i <= b:
			ans += 1
	print ans
