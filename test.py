files = open("./roman.txt")
lines = files.readlines()
for line in lines:
	print line.split("=")[1][:-1]
# count  = 0
# for i in range(1,5000):
# 	count += 1
# print count
# for i in range(1,5000):
# 	print i