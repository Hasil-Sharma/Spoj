from math import sqrt
def distance(coord,other):
	return (coord[0] - other[0])**2 + (coord[1] - other[1])**2 

def main():
	n = input()
	i = 0
	coords = []
	while i < n:
		i += 1
		a,b = map(int,raw_input().split())
		coords.append((a,b))
	max_dist = 0
	for coord in coords:
		for other in coords:
			dist = distance(coord,other)
			if dist > max_dist:
				max_dist = dist
	print sqrt(max_dist)

if __name__ == '__main__':
	main()