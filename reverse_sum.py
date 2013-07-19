import sys
input_data = sys.stdin.read()
input_data = input_data.split('\n')
input_data.remove('')
number_index = int(input_data[0])
index = 1
while index <= number_index:
	numbers = (input_data[index])
	numbers = numbers.split(' ')
	a = numbers[0]
	b = numbers[1]
	a,b = map(list,[a,b])
	a.reverse()
	b.reverse()
	a = ''.join(a)
	b = ''.join(b)
	a,b = map(int,[a,b])
	sol = a + b
	sol = str(sol)
	sol = list(sol)
	sol.reverse()
	sol = ''.join(sol)
	sol = sol.strip('0')
	print sol
	index = index + 1
