import sys
input_data = sys.stdin.readlines()
t = int(input_data[0])
i = 1
try:
    while True:
        lst = []
        data = input_data[i:i+99]
        for da in data:
            num,char = da.split()
            if char in lst:
                print "NO"
                break
            else:
                lst.append(char)
        i += 99
except:
    pass
