import sys
input_data = sys.stdin.read()
input_data = input_data.split('\n\n')
index = 0
t = input_data[index]
t = int(t)
while index < t:
    input = input_data[index + 1]
    input = input.split('\n')
    if '' in input:
        input.remove('')
    input = map(int,input)
    index +=1
    i = 1
    sum = 0
    n = input[0]
    while i <= n:
        sum += input[i]
        i += 1
    if sum % n == 0:
        print "YES"
    else:
        print "NO"