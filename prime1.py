import sys
input_data = sys.stdin.readlines()
new = []
for data in input_data:
	new.append(data.strip('\n'))
t = int(data[0])
for i in xrange(1,t+1):
	numbers = data[i]
	numbers = numbers.split(' ')
	numbers = map(int,numbers)
	get_list = find_primes(numbers[0],numbers[1])
