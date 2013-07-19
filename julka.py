'''
Created on 02-Jan-2013

@author: Hasil
'''
import sys
input_data = sys.stdin.read()
input_data = input_data.split('\n')
input_data.remove('')
input_data = map(int,input_data)
maxi = 20
index = 0
while index < maxi:
        total = input_data[index]
        add_to_y = input_data[index + 1]
        x = total/2 + add_to_y/2
        y = total - x
        print x
        print y
        index +=2
        