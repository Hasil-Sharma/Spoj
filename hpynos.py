SQUARE = dict([(c, int(c)**2) for c in "0123456789"])
s = set()
def is_happy(n):
  i = 0
  while (n > 1) and (n not in s):
	s.add(n)
	n = sum(SQUARE[d] for d in str(n))
	i += 1
  return (n == 1,i)
  
def main():
	i = 0
	while (i < 32):
		n = input()
		ans = is_happy(n)
		if ans[0]:
			print ans[1]
		else:
			print -1
	i += 1

if __name__ == '__main__':
	try:
		main()
	except:
		pass
