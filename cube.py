import sys
input_data = sys.stdin.read()
input_data = input_data.split('\n')
input_data.remove('')
input_data = map(int,input_data)
t = input_data[0]
index = 1
dict = {1:192, 2:442, 3:692, 4:942}
while index <= t:
	num = input_data[index]
	index += 1
	a = num % 4
	b = num / 4
	if a == 0:
		a = 4
		b = b-1
	print dict[a] + b*1000
	
	
