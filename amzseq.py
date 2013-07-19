import sys
input_data = sys.stdin.readlines()
input_data = int(input_data[0].rstrip())
def break_list(n):
	new_list= []
	for i in n:
		if i == 2 :
			new_list.extend([2,3])
		elif i == 3:
			new_list.extend([2,3,2])
	return new_list

n = [3]
i = 1
while i < input_data:
	n = break_list(n)
	i += 1
print sum(n)

