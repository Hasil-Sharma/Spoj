import sys
input_data = sys.stdin.readlines()
input_data = [i.rstrip() for i in input_data]
x = int(input_data.pop(0))
input_datas = [input_data[n:n+2] for n in range(0,len(input_data),2)]
for data in input_datas:
	number_of_jobs,job_position = map(int,data[0].split())
	queue = map(int,data[1].split())
	new_queue = []
	for item in queue:
		new_queue.append([item,False])
	new_queue[job_position][1] = True
	time = 0
	while True:
		mx = max(new_queue)[0]
		if mx == new_queue[0][0]:
			temp = new_queue.pop(0)
			time += 1
			if temp[1]:
				break
		else:
			temp = new_queue.pop(0)
			new_queue.append(temp)
	print time




