def find_coins(n):
	if n in find_coins.dictionary:
		return find_coins.dictionary[n]
	elif n/2 + n/3 + n/4 <= n:
		find_coins.dictionary[n] = n
		return find_coins.dictionary[n]
	else:
		find_coins.dictionary[n] = find_coins(n/3) + find_coins(n/2) + find_coins(n/4)
		return find_coins.dictionary[n]
import sys
input_Data = sys.stdin.read()
input_Data = input_Data.split("\n")
input_Data.remove("")
input_Data = map(int,input_Data)
index = 0
find_coins.dictionary = {}
while index < len(input_Data):
    num = input_Data[index]
    index +=1
    ans = find_coins(num)
    print ans
