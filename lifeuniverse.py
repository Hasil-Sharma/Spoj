import sys
input_data = sys.stdin.read()
input_data = input_data.split('\n')
input_data.remove('')
for element in range(len(input_data)):
	input_data[element] = int(input_data[element])
for element in input_data:
	if element != 42:
		print element
	else:
		break



