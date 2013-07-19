def main():
	n,m = map(int,raw_input().split())
	while n != 0 and m != 0:
		i = 0
		calls = []
		while i < n:
			calls.append(map(int,raw_input().split()))
			i += 1
		intervals = []
		k = 0
		# while i < m:
		# 	intervals.append(map(int,raw_input().split()))
		# 	i += 1
		# for interval in intervals:
		# 	num = 0
		# 	record = []
		# 	#print interval
		# 	calles = calls[:]
		# 	for i in range(interval[0],interval[1]+interval[0]):
		# 		#print "here"
		# 		for call in calles:
		# 			if i >= call[2] and i < call[2]+call[3]:
		# 				calles.remove(call)
		# 				num += 1
		# 			#print "checking for",i,"in",call, "num :",num, "call already tpped :",call in record
		# 	print num

		while k < m :
			k += 1
			interval = map(int,raw_input().split())
			num = 0
			record = []
			#print interval
			calles = calls[:]
			for i in range(interval[0],interval[1]+interval[0]):
				#print "here"
				for call in calles:
					if i >= call[2] and i < call[2]+call[3]:
						calles.remove(call)
						num += 1
					#print "checking for",i,"in",call, "num :",num, "call already tpped :",call in record
			print num
		n,m = map(int,raw_input().split())
if __name__ == '__main__':
	main()