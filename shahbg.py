import sys
input_data = sys.stdin.readlines()
dictionary = {}
data = map(int,input_data[1].split())
maxd,mind = max(data),min(data)
for x in range(mind, maxd+1):
	dictionary[x] = False
data = map(int,input_data[1].split())
for i in data:
	try:
		dictionary[i] = True
		group = 0
		a = False
		for x in range(mind, maxd+1):
			if a:
				if not dictionary[x]:
					a = False
			elif dictionary[x] :
				group += 1
				a = True
		print group
	except:
		pass
print "Justice"

