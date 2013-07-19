def factors(num):
	if num in factors.dict:
		return factors.dict[num]
	else:
		i = 1
		count = 0
		while i <= num/i:
			if num % i == 0:
				count += 1
			i += 1
		factors.dict[num] = count
		return count
		
import sys
input_data = sys.stdin.read()
input_data = input_data.split('\n')
num = int(input_data[0])
factors.dict = {}
number_rectangles = 0
while num > 0:
	number_rectangles += factors(num)
	num -= 1
print number_rectangles