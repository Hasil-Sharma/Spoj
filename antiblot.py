import sys
input_data = sys.stdin.read()
input_data = input_data.split('\n\n')
t = int(input_data[0])
index = 1
while index <= t:
	string = input_data[index]
	index += 1
	string = string.split(' ')
	if 'machula' in string[2]:
		string[2] = str(int(string[4]) - int(string[0]))
		string = ' '.join(string)
		print string
		
	elif 'machula' in string[0]:
		string[0] = str(int(string[4]) - int(string[2]))
		string = ' '.join(string)
		print string
		
	else:
		string[4] = str(int(string[0]) + int(string[2]))
		string = ' '.join(string)
		print string
		
