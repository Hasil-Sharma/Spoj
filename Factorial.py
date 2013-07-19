import sys
input_data = sys.stdin.read()
input_data = input_data.split('\n')
input_data.remove('')
input_data = map(int,input_data)
number_index = input_data[0]
index = 1
while  index <= number_index:
	i = 1
	val = 0
	while input_data[index]/(5**i) > 0:
		val += input_data[index]/(5**i)
		i += 1
	print val
	index +=1
