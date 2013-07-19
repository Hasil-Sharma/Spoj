def main():
	t = input()
	i = 0
	while i < t:
		a = False
		i += 1
		n = input()
		j = 0
		lst = map(int,raw_input().split())
		lst = sorted(lst)
		j = 0
		temp = []
		while j < n - 2 :
			if lst[j] == lst[j+1]:
				temp.append(lst.pop(j))
			else:
				j += 1
		if list(set(temp)) == temp:
			print "YES"
		else:
			print "NO"


if __name__ == '__main__':
	main()