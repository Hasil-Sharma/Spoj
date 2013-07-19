import sys
input_data = sys.stdin.read()
input_data = input_data.split('\n')
input_data.remove('')
index_n = 0
index_l = 1
while True:
    input = input_data[index_n]
    if input == '0':
        break
    index_n += 2
    input = input_data[index_l].split(' ')
    index_l += 2
    input = map(int,input)
    i = 0
    dictionary = {}
    while i < len(input):
    	dictionary[i+1] = input[i]
    	i += 1
    dictionary = dictionary.items()
    dict = {}
    for element in dictionary:
    	dict[element[1]] = element[0]
    output = dict.values()
    if output == input:
    	print "ambiguous"
    else:
    	print "not ambiguous"    
