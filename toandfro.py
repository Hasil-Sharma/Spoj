import sys
input_data = sys.stdin.read()
input_data = input_data.split('\n')
input_data.remove('')
index = 0
while True:
    column_len = int(input_data[index]) #length of the column of rectangular array
    if column_len == 0:
        break
    encrypt_string =list(input_data[index + 1]) # the encrypted to and fro string 
    s_index = 0
    encrypt_line_list = []
    while s_index < len(encrypt_string):
        a = ''.join(encrypt_string[s_index : s_index + column_len])
        encrypt_line_list.append(a)
        s_index += column_len
    s_index = 1
    while s_index < len(encrypt_line_list):
        a = encrypt_line_list[s_index]
        encrypt_line_list[s_index] = a[::-1]
        s_index += 2
    i = 0
    a = ''
    while i < column_len:
        for string in encrypt_line_list:
            a += string[i]
        i += 1
    print a
    index += 2
   
        
    