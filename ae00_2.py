def solution(n,i,temp):
	if temp >= 0:
		return temp + solution(n,i+1,n/i - i + 1)
	else:
		return 0

n = input()
ans = solution(n,2,n)
print ans
