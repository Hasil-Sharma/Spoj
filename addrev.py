import sys
def reverse_int(integer):
	ans = 0
	while (integer > 0):
		ans = ans*10 + integer % 10
		integer = integer/10
	return ans

def main():
	input_data = sys.stdin.readlines()
	t = int(input_data[0])
	for i in range(1,t+1):
		a,b = map(int,input_data[i].split())
		print reverse_int(reverse_int(a)+reverse_int(b))

if __name__ == '__main__':
	main()
