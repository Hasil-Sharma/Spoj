import sys
input_data = sys.stdin.readlines()
def main():
	t = int(input_data[0])
	i = 1
	while i <= 2*t:
		n = int(input_data[i])
		i += 1
		data = {0:0}
		data = {j:input_data[i].split().count(j) for j in input_data[i].split() if input_data[i].split().count(j) > n/2 }
		i += 1
		try:
			value = max(data, key = lambda x:data[x])
			if data[value] > n/2:
				print "YES %s" %(value)
			else:
				print "NO"
		except:
			print "NO"
if __name__ == '__main__':
	main()

