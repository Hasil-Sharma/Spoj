import sys
input_data =  sys.stdin.readlines()
del input_data[0]
input_data = [i.rstrip(' =\n') for i in input_data if i.rstrip(' =\n') ]
for data in input_data:
	a = data.split()
	ans = 0
	string = ''
	while True:
		if len(a) >= 3 :
			x,y = map(int,[a[0],a[2]])
			sign = a[1]
			if sign == '+':
				ans = x+y

			elif sign == '-':
				ans = x-y

			elif sign == '*':
				ans = x*y

			else:
				ans = x/y

			for i in [0,0,0]:
				a.pop(0)
			a.insert(0,ans)
		else:
			print ans
			break