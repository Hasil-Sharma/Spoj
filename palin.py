def find_palin(n_str,n_int):
    while True:
        n_int +=1
        n_str = str(n_int)
        if n_str == n_str[::-1]:
            return n_str
import sys
input_data = sys.stdin.read()
input_data = input_data.split('\n')
input_data.remove('')
t = int(input_data[0])
index = 1
while index <= t:
    number_str = input_data[index]
    number_int = int(input_data[index])
    result = find_palin(number_str,number_int)
    print result
    index +=1