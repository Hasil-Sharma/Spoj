from math import sqrt
g_dict = {}
f_dict = {1:8,2:8}

def F(n):
	if n in f_dict:
		return f_dict[n]
	else:
		f_dict[n] = 8 + pow((n-2)/(1.0*n),2)*F(n-2)
		return f_dict[n]

def G(n):
	if n in g_dict:
		return g_dict[n]
	else:
		g_dict[n] = sqrt(8*(pow(n,2)-pow((n-1),2))+pow((n-2),2)*F(n-2) - pow((n-3),2)*F(n-3) + 1.0)/(1.0*n)
	return g_dict[n]

def main():
	t = input()
	i =0
	while i < t:
		i += 1
		n = input()
		g = G(n)
		print "%.8f" % (round(g,8))

if __name__ == '__main__':
	main()