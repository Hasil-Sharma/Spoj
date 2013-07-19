import sys
try:
	for data in sys.stdin.readlines():
		if int(data) == 1:
			print 1
		else:
			print 2*(int(data)-1)
except:
	pass