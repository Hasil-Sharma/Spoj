'''
Created on 02-Jan-2013

@author: Hasil
'''
import sys
input_data = sys.stdin.read()
input_data = input_data.split('\n')
input_data.remove('')
index = 1
n = int(input_data[0])
while index <= n:
    coordinate = input_data[index]
    x,y = coordinate.split(' ')
    x,y = int(x),int(y)
    if abs(x-y) == 0 or (x-y) == 2:
        if x % 2 == 0 and y % 2 == 0:
            print x + y
        else:
            print x + y - 1
    else:
        print 'No Number'
    index +=1

