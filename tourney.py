import sys
input_data = sys.stdin.readlines()
n = int(input_data[0].split()[0])
power = {}
tourney = []
for i in range(1,2**n+1):
	power[i] = int(input_data[i])
	tourney.append(power[i])

for data in input_data[2**n+1:]:
	cmd = data.split()
	if cmd[0] == "R":
		i,s = map(int,[cmd[1],cmd[2]])
		power[i] = s
		tourney[i - 1] = s

	elif cmd[0] == "W":
		value = max(tourney)
		for key in power:
			if power[key] == value:
				print key
				break

	elif cmd[0] == "S":
		i = int(cmd[1])
		hp = power[i]
		temp = tourney[:]
		j = 0
		temp = [max([temp[i],temp[i+1]]) for i in range(0,len(temp),2)]
		while len(temp) > 1:
			if hp == max(temp):
				j = n
				break
			elif hp in temp:
				j += 1
				temp = [max([temp[i],temp[i+1]]) for i in range(0,len(temp),2)]
			else:
				break
		del temp
		print j



