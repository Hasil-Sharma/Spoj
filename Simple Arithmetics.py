def spliter(string):
	operators = ['+','*','-']
	for opertor in operators:
		if opertor in computation_string:
			numbers = computation_string.split(opertor)
			numbers.append(opertor)
			return numbers

def computation(a,b,operator):
	if operator == '+':
		return a + b
	elif operator == '-':
		return a - b
	elif operator == '*':
		return a*b
		
def add_spaces(string,spaces):
	while spaces > 0:
		string = ' ' + string
		spaces = spaces - 1
	return string
			
def question_printing(a,b,answer):
	reference_length = max(map(len,[a,b,answer]))
	a = add_spaces(a,reference_length-len(a))
	b = add_spaces(b,reference_length-len(b))
	answer = add_spaces(answer,reference_length-len(answer))
	lists = [a,b,answer,reference_length]
	return lists

def dash_gen(b,answer):
	reference_length = max(map(len,[b,answer]))
	string = ['-']*reference_length
	string = ''.join(string)
	return string
	
def add_spaces_front(string,spaces):
	while spaces > 0:
		string = string + ' '
		spaces = spaces - 1
	return string
	 
import sys
input_data = sys.stdin.read()
input_data = input_data.split('\n')
input_data.remove('')
number_of_lines= int(input_data[0])
index = 0
while index < number_of_lines:
	index += 1
	computation_string = input_data[index]
	numbers = spliter(computation_string)
	for num in (0,1):
		numbers[num] = int(numbers[num])
	num_1,num_2,operator =numbers[0],numbers[1],numbers[2]
	answer = computation(num_1,num_2,operator)
	num_1,num_2,answer=map(str,[num_1,num_2,answer])
	num_2_without_space = num_2 
	answer_without_space = str(answer)
	num_2 = operator + num_2
	if operator != '*':
		dash_string = dash_gen(num_2,answer)
	question_string = question_printing(num_1,num_2,answer)
	print question_string[0]
	print question_string[1]
	if operator != '*':
		dash_string = add_spaces(dash_string,question_string[3]-len(dash_string))
		print dash_string
		print question_string[2]
		continue
	else:
		if len(num_2) == 2:
			dash_string = dash_gen(num_2,answer)
			dash_string = add_spaces(dash_string,question_string[3]-len(dash_string))
			print dash_string
			print question_string[2]
		else:
			num_1 = int(num_1)
			spaces_on_front = 0
			num_2_string = num_2.strip('*')
			num_2_string = list(num_2_string)
			num_2_string.reverse()
			num_2_length = len(num_2_string)
			step_1 = str(int(num_2_string[0])*num_1)
			dash_string = dash_gen(step_1,'*'+num_2_without_space)
			dash_string = add_spaces(dash_string,question_string[3]-len(dash_string))
			print dash_string
			for number in num_2_string:
				step = str(int(number)*num_1)
				step = add_spaces_front(step,spaces_on_front)
				spaces_on_front +=1
				step_without_spaces = step
				step = add_spaces(step,question_string[3]-len(step))
				print step
			dash_string = dash_gen(step_without_spaces,answer_without_space)
			dash_string = add_spaces(dash_string,question_string[3]-len(dash_string))
			print dash_string
			print question_string[2]
print '\n'
			
