def main():
	t = input()
	i = 0
	while (i < t):
		b = raw_input()
		ng,nm = map(int,raw_input().split())
		ngs = max(raw_input().split())
		nms = max(raw_input().split())
		if ngs >= nms:
			print "Godzilla"
		else:
			print "MechaGodzilla"
		i += 1

if __name__ == '__main__':
	main()