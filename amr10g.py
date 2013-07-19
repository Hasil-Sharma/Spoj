import sys
input_data = sys.stdin.readlines()
def main():
	t = int(input_data[0])
	i = 1
	while i <= 2*t:
		n,k = map(int,input_data[i].split())
		i += 1
		heights = sorted(map(int,input_data[i].split()))
		j = 0
		diff = heights[-1]
		while(j <= n-k):
			temp_diff = heights[j+k-1] - heights[j]
			if temp_diff < diff:
				diff = temp_diff
			j += 1
		i += 1
		print diff

if __name__ == '__main__':
	main()