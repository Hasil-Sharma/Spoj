def foramtter(string):
	
import sys
input_data = sys.stdin.read()
input_data = input_data.split('\n')
input_data.remove('')
index = 0
while input_data[index] != '-1':
	t = int(input_data[index])
	seq = input_data[index + 1]
	seq = seq.split(' ')
	seq = map(int,seq)
	i = 0
	string = ''
	while i < t -1:
	
		if seq[i] < seq[i+1]:
			string += '/'
		elif seq[i] > seq[i+1]:
			string += "\\"
		else:
			string += "_"
		i += 1
	string = foramtter(string)
	print '***'
	index += 2
	
