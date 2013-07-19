import sys
input=sys.stdin.read()
input=input.split('\n')
input.remove('')
t=int(input[0])
index = 1
while index <= t:
    a,b = (input[index].split(' '))
    a,b = int(a),int(b)
    if b == 0:
        print "1"
    elif b%4 == 0:
        b = 4
        num = str(a**b)
        print num[len(num) - 1]
    else:
        b = b%4
        num = str(a**b)
        print num[len(num) - 1]
    index += 1