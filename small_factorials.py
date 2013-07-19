def factorial(n):
    if n == 1 or n == 0:
        return 1
    else:
        return n*factorial(n-1)
import sys
input_data = sys.stdin.read()
input_data = input_data.split('\n')
input_data.remove('')
input_data = map(int,input_data)
t = (input_data[0])
index = 1
while index <= t :
    num = input_data[index]
    print factorial(num)
    index +=1