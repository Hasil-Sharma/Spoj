def main():
	while True:
		a = list(raw_input())
		b = list(raw_input())
		ans = []
		for x in a:
			if x in b:
				ans.append(x)
				b.remove(x)
		print ''.join(sorted(ans))
if __name__ == '__main__':
	try:
		main()
	except:
		pass