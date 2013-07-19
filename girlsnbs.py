from math import ceil
def main():
	input_data = map(int,raw_input().split())
	n,m = sorted(input_data)
	while n != -1 and m != -1:
		print "%d" % ceil(m/(n+1.0))
		input_data = map(int,raw_input().split())
		n,m = sorted(input_data)

if __name__ == '__main__':
	main()