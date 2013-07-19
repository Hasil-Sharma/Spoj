dct = {'1/2':0.5,'1/4':0.25,'3/4':0.75}
def main():
	n = input()
	i = 0
	left = [0]
	ans = 0
	while i < n :
		found = False
		i += 1
		apizza = raw_input()
		left = sorted(left,reverse = True)
		j = 0
		ans = 1
		while j < len(left) - 1:
			if left[j] >= dct[apizza] and left[j+1] < dct[apizza]:
				left[j] = left[j] - dct[apizza]
				found = True
				break
			else:
				j += 1
		if found:
			pass
		else:
			ans += 1
	print ans

if __name__ == '__main__':
	main()
