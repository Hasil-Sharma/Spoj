import sys
i_d = sys.stdin.read()
i_d = input_data.split('\n')
i_d.remove('')
maxm = len(i_d)
dictionary = {'T':'K','D':'G','L','R'}
index = 0
while index < maxm :
	i_s = i_d[index]
	
