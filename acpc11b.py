def main():
	t = input()
	i = 0
	while (i < t):
		i += 1
		mount1 = map(int,raw_input()[2:].split())
		mount2 = map(int,raw_input()[2:].split())
		mount1.sort()
		mount2.sort()
		print abs(mount2[0]-mount1[0])
if __name__ == '__main__':
	main()