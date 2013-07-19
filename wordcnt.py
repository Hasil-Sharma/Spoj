import sys
from collections import Counter
import itertools
input_data =  sys.stdin.readlines()
del input_data[0]
input_data = [i.rstrip() for i in input_data]
for data in  input_data:
	data = data.split()
	data = itertools.groupby(data,lambda x : len(x))
	patterns = []
	for i in data:
		seq = []
		try:
			while True:
				seq.append(i[1].next())
		except:
			pass
		patterns.append(seq)
	print max(map(len,patterns))
	
