import sys
input_data = sys.stdin.readlines()
input_data.pop(0)
dictionary = {}
def odd(i):
	if i in dictionary:
		return dictionary[i]
	else:
		n = (i -2)/10 + 1
		dictionary[i] = 2*n -1
		return dictionary[i]

def even(i):
	if i in dictionary:
		return dictionary[i]
	else:
		n = (i -11)/10 + 1
		dictionary[i] = 2*n
		return dictionary[i]
		
for i in input_data:
	try:
		a = False
		i = i.rstrip()
		if i == '1':
			print "poor conductor"
			a = True
		elif i.endswith('2') or i.endswith('1'):
			seat_position = 'W'
			direction = 'L'
			if i.endswith('2'):
				i = int(i)
				row_number = odd(i)
			else:
				i = int(i)
				row_number = even(i)

		elif i.endswith('3') or i.endswith('0'):
			seat_position = 'A'
			direction = 'L'
			if i.endswith('3'):
				i = int(i)-1
				row_number = odd(i)
			else:
				i = int(i)+1
				row_number = even(i)

		elif i.endswith('4') or i.endswith('9'):
			seat_position = 'A'
			direction = 'R'
			if i.endswith('4'):
				i = int(i)-2
				row_number = odd(i)
			else:
				i = int(i)+2
				row_number = even(i)

		elif i.endswith('5') or i.endswith('8'):
			seat_position = 'M'
			direction = 'R'
			if i.endswith('5'):
				i = int(i) - 3
				row_number = odd(i)
			else:
				i = int(i) + 3
				row_number = even(i)

		elif i.endswith('6') or i.endswith('7'):
			seat_position = 'W'
			direction = 'R'
			if i.endswith('6'):
				i = int(i) - 4
				row_number = odd(i)
			else:
				i = int(i) + 4
				row_number = even(i)
		if not a:
			print row_number, seat_position, direction
	except:
		pass



			

