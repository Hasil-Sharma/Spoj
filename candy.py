import sys
input_data = sys.stdin.read()
input_data = input_data.split('\n')
input_data.remove('')
input_data = map(int,input_data)
index = 0
while input_data[index] != -1:
    n = input_data[index]
    a = input_data[index:index+n+1]
    sums = sum(a)
    mean = sums/n
    if sums % n == 0 :
        print max(a) - mean
    else:
        print -1
    index += n+1
    