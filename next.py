def is_AP(a,b,c):
    if b-a == c-b:
        return True
    else:
        return False
import sys
input_Data = sys.stdin.read()
input_Data = input_Data.split('\n')
input_Data.remove('')
index = 0
while True:
    a,b,c = input_Data[index].split(' ')
    index +=1
    a,b,c = int(a),int(b),int(c)
    if a == 0 and b == 0 and c == 0:
        break
    if is_AP(a,b,c):
        print "AP",c+b-a
    else:
        print "GP",c*(b/a)