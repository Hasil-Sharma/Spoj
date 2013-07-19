import itertools
def main():
	t = input()
	j = 0
	while j < t:
		j += 1
		n = input()
		maxnumber = map(int,raw_input().split())
		a = [range(1,i+1) for i in maxnumber]
		print len(set([i for i in itertools.product(*a)]))
	print "KILL BATMAN"

if __name__ == '__main__':
	main()