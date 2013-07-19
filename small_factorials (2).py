'''
Created on 02-Jan-2013

@author: Hasil
'''
def factorial(n):
    if n == 1 or n == 0 :
        return 1
    else:
        return n*f(n-1)
import sys
input = sys.stdin.readline()
print input