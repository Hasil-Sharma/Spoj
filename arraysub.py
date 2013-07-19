def main():
	try:
		n = input()
		b = raw_input()
		array = raw_input().split()
		k = input()
		ans = []
		temp = array[:k]
		array = array[k:]
		while array:
			ans.append(max(temp))
			temp.pop(0)
			temp.append(array.pop(0))
		ans.append(max(temp))
		print ' '.join(ans)
	except:
		pass

if __name__ == '__main__':
	main()