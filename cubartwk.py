def main():
	w,d = map(int,raw_input().split())
	while (w != 0 and d !=0):
		ans = 0
		h = map(int,raw_input().split())
		_h = map(int,raw_input().split())
		if w >= d:
			for x in h:
				if x in _h:
					ans += x
					_h.remove(x)
				else:
					ans += x
			ans += sum(_h)
		else:
			for x in _h:
				if x in h:
					ans += x
					h.remove(x)
				else:
					ans += x
			ans += sum(h)
		print ans
		w,d = map(int,raw_input().split())

if __name__ == '__main__':
	main()