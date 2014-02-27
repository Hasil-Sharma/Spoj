from sys import stdin,stdout
lst = []
mod = 1298074214633706835075030044377087
lst.append(1)
n = 1
while(n <= 501):
	lst.append(((lst[n-1]%mod) << 1)%mod)
	n += 1
data = map(int,stdin.readlines())
index = 1
limit = data[0]
while index <= limit:
	n = data[index]
	index += 1
	i = 0
	ans = 0
	ans = lst[n+1] - 1
	stdout.write(str(ans%mod) + '\n')