def main():
	while True:
		n,k = map(int,raw_input().split())
		lst = sorted(map(int,raw_input().split()))
		ans = 0
		for i in lst:
			if i+k in lst:
				ans+=1
		print ans

if __name__ == '__main__':
	try:
		main()
	except:
		pass