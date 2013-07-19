import sys
input_data = sys.stdin.read()
input_data = input_data.split('\n')
input_data.remove('')
a = int(input_data[0])
index = 1
while index < a:
	nums = input_data[index]
	a,b = nums.split(' ')
	a,b = int(a),int(b)
	print a*b
	index +=1
