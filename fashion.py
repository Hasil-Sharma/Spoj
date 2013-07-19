import sys
input_data = sys.stdin.read()
input_data = input_data.split('\n')
input_data.remove('')
t = input_data[0]
t = int(t)
index = 1
while index <= 3*t:
	 n = input_data[index]
	 n = int(n)
	 x_list = input_data[index + 1].split(' ')
	 x_list = map(int,x_list)
	 x_list.sort()
	 y_list = input_data[index + 2].split(' ')
	 y_list = map(int,y_list)
	 y_list.sort()
	 i = 0
	 sum = 0
	 while i < n:
		 sum += y_list[i] * x_list[i]
		 i += 1
	 print sum
	 index += 3
		 