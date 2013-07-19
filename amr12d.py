def substr(string):
    j=1
    a=set()
    while True:
        for i in range(len(string)-j+1):
            a.add(string[i:i+j])
        if j==len(string):
            break
        j+=1
        #string=string[1:]
    return a
import sys
input_data = sys.stdin.readlines()
del input_data[0]
input_data = [i.rstrip() for i in input_data]
for string in input_data:
	substrings = substr(string)
	b = [a[::-1] in string for a in substrings ]
	if all(b) == True:
		print "YES"
	else:
		print "NO"