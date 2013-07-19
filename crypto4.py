#Finds the values of x and y that can be used for solving the problem and puts them in a dictionary with key as the index of character in strings
def x_y_finder(x,y):
	index = 0
	x_i,y_i = {},{}
	while index < len(x):
		if x[index] != '*' and y[index] != '*':
			x_i[index] = x[index]
			y_i[index] = y[index]
		index +=1
	return x_i,y_i
#gives possible values of k for the calculation of n but key of k is not the actual key
def find_value_k(y,x):
	k = 0
	while True:
			if (x + k) % 26 == y: 
				return k
			k +=1	
			
def k_equation_gen(x_dict,y_dict,mapping):
	indexes = x_dict.keys()
	k_needed = {}
	for index in indexes:
		y_i = mapping[y_dict[index]]
		x_i = mapping[x_dict[index]]
		k_needed[index - 1] = find_value_k(y_i,x_i)
	return k_needed
#gives the corrected needed keys of the values of k and also gives the sought value of n
def k_values(k_possible,n):
	indexes = k_possible.keys()
	k_possible_1 = {}
	for index in indexes :
		k_possible_1[1+(index % n)] = k_possible[index]
	return k_possible_1
	
def value_of_x(y_i,k_i):
	for x in xrange(0,26):
		if (x+k_i)%26 == y_i:
			return x
			
def solution(n,values_k,x,y,mapping,reverse_mapping):
	x,y = list(x),list(y)
	keys_k = values_k.keys()
	index = 0
	while index <  len(x):
		if x[index] != '*' and y[index] != '*':
			pass
		if x[index] != '*' and y[index] == '*':
			pass
		if x[index] == '*' and y[index] != '*':
			y_i = mapping[y[index]]
			key_k = 1 + ((index - 1) % n)
			if key_k in keys_k:
				x[index] =  value_of_x(y_i , values_k[key_k])
				x[index] = reverse_mapping[x[index]]
			else:
				pass
		else:
			pass
		index += 1
	return x
		
	
			
	
import sys
input_data = sys.stdin.read()
input_data = input_data.split('\n')
input_data.remove('')
t = int(input_data[0])
input_data_organised = []
alphabets = map(chr,range(65,91))
mapping = {}
reverse_mapping = {}
for alphabet in alphabets:
	mapping[alphabet] = alphabets.index(alphabet)
	reverse_mapping[alphabets.index(alphabet)] = alphabet
index = 1 
	

"""Organising data in sets of three in a list where one element of list consists of a list having three elements as m,x,y respectively"""
while index + 2 < len(input_data):
	input_data_organised.append([int(input_data[index]),input_data[index + 1],input_data[index + 2]])
	index +=3
index = 0
"""Taking one element of the list at a time """
while index < t:
	data = input_data_organised[index]
	m,x,y = data[0],data[1],data[2] #taking values as m,x,y
	x_y = x_y_finder(x,y)
	x_dict = x_y[0]
	y_dict = x_y[1]
	k_possible=k_equation_gen(x_dict,y_dict,mapping)
	limit = len(k_possible)
	for n in xrange(1,m+1):
		values_k = k_values(k_possible,n)
		if len(values_k) == limit:
			break
	ans_string = solution(n,values_k,x,y,mapping,reverse_mapping)
	print ''.join(ans_string)
	index +=1
