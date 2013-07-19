import sys

def setting(n,seq):
	orignal_seq = seq[:]
	enteranceroad = seq
	exitroad, sideroad = [],[]
	i = 0
	while len(enteranceroad) > 0:
		leading_truck = enteranceroad[-1]
		if leading_truck > min(enteranceroad):
			if len(sideroad) == 0:
				sideroad.insert(0,enteranceroad.pop(-1))
			else:
				if sideroad[0] < leading_truck :
					exitroad.insert(0,sideroad.pop(0))
				else:
					sideroad.insert(0,enteranceroad.pop(-1))
		else:
			if len(sideroad) > 0 and sideroad[0] < enteranceroad[-1]:
				exitroad.insert(0,sideroad.pop(0))
			else:
				exitroad.insert(0,enteranceroad.pop(-1))
		# print "i: ",i
		# print "enteranceroad:", enteranceroad
		# print "exitroad: ", exitroad
		# print "sideroad: ",sideroad
	for truck in sideroad:
		exitroad.insert(0,truck)
	orignal_seq.sort()
	exitroad.reverse()
	if exitroad == orignal_seq:
		return "yes"
	else:
		return "no"

input_data = sys.stdin.read().split()
input_data = map(int,input_data)
while True:
	n = input_data.pop(0)
	if n == 0:
		break
	else:
		seq = []
		j = 0
		while j < n:
			temp = input_data.pop(0)
			seq.append(temp)
			j += 1
		seq.reverse()
		sol = setting(n,seq)
		print sol


