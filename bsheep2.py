import sys
from math import sqrt
def tupling(a):
	a = a.split(' ')
	return tuple(map(int,(a[0],a[1])))

def get_key(value, dictionary):
	for key,values in dictionary.items():
		if values == value:
			return key

def finding_abcd(data):
	dif = {}
	sum = {}
	for point in data:
		dif[point] = point[0] - point[1]
		sum[point] = point[0] + point[1]
	max_difference = max(dif.values())
	a = get_key(max_difference,dif)
	max_summation = max(sum.values())
	b = get_key(max_summation,sum)
	min_difference = min(dif.values())
	c = get_key(min_difference,dif)
	min_summation = min(sum.values())
	d = get_key(min_summation,sum)
	return a,b,c,d

def is_inrectangle(point,rectangle):
	y1 = rectangle[0][1]
	x2 = rectangle[0][0]
	x1 = rectangle[2][0]
	y2 = rectangle[2][1]
	x = point[0]
	y = point[1]
	if y2 > y and y > y1 and x > x1 and x2 > x:
		return True
	else:
		return False

def prune(data,rectangle):
	for point in data:
		if is_inrectangle(point,rectangle):
			data.pop(data.index(point))
	return data


# def convex_hull(points):
# 	points = sorted(set(points))

# 	if len(points) <= 1:
# 		return points

# 	def cross(o, a, b):
# 		return (a[0] - o[0]) * (b[1] - o[1]) - (a[1] - o[1]) * (b[0] - o[0])

# 	lower = []
# 	for p in points:
# 		while len(lower) >= 2 and cross(lower[-2], lower[-1], p) <= 0:
# 			lower.pop()
# 		lower.append(p)
# 	upper = []
# 	for p in reversed(points):
# 		while len(upper) >= 2 and cross(upper[-2], upper[-1], p) <= 0:
# 			upper.pop()
# 		upper.append(p)
# 	return lower[:-1] + upper[:-1]
def cross(v1, v2):
    ''' return the cross product of two vectors 
    '''
    return (v1[0] * v2[1]) - (v1[1] * v2[0])

def dot(v1, v2):
    ''' return the dot product of two vectors 
    '''
    return v1[0] * v2[0] + v1[1] * v2[1]

def angle_cmp(pivot):
    ''' receive a coord as the pivot and return a 
    function for comparing angles formed by another
    two coords around the pivot
    '''
    def _angle_cmp(c1, c2):
        v1 = c1[0] - pivot[0], c1[1] - pivot[1]
        v2 = c2[0] - pivot[0], c2[1] - pivot[1]
        cp = cross(v1, v2)
        if cp < 0:
            return 1
        elif cp == 0:
            return 0
        else:
            return -1
    return _angle_cmp

def turnning(c1, c2, c3):
    ''' detemine which way does c1 -> c2 -> c3 go
    '''
    v1 = c2[0] - c1[0], c2[1] - c1[1]
    v2 = c3[0] - c2[0], c3[1] - c2[1]
    cp = cross(v1, v2)
    if cp < 0:
        return 'RIGHT'
    elif cp == 0:
        return 'STRAIGHT'
    else:
        return 'LEFT'
    

def graham_scan(coords):
    ''' 
    Parameters:
        [(x, y)] - List of cartesian coordinates

    Return:
        [(x, y)] - List of vertex of the target convex hull
    '''
    num = len(coords)
    if num < 3:
        return coords

    # sort the coords according to x
    coords.sort()

    # select the leftmost coord as the pivot
    pivot = coords[0] 
    coords = coords[1:]

    # for remaining coords, sort them by polar angle
    # in counterclockwise order around pivot
    coords.sort(angle_cmp(pivot)) 
    
    # push the first three coords in a stack
    stack = []
    stack.append(pivot)
    stack.append(coords[0])
    stack.append(coords[1])
    
    # for the rest of the coords, while the angle formed by 
    # the coord of the next-to-top of the stack, coord of 
    # top of stack and the next coord makes a nonleft turn, 
    # pop the stack
    # also, push the next coord into the stack at each loop
    for i in range(2, num - 1):
        while len(stack) >= 2 and \
              turnning(stack[-2], stack[-1], coords[i]) != 'LEFT':
            stack = stack[:-1]
        stack.append(coords[i])
    return stack

input = sys.stdin.readlines()
inpute = []
for i in input:
	i = i.strip('\n')
	if i != "":
		inpute.append(i.strip('\n'))

input_data = inpute
t = int(input_data.pop(0))
j = 0
while j < t:
	j += 1
	n = int(input_data.pop(0))
	data = []
	i = 0
	while i < n:
		data.append(input_data.pop(0))
		i += 1
	data = map(tupling,data)
	dictionary = {}
	i = 1
	for points in data:
		dictionary[i] = points
		i += 1

	a,b,c,d = finding_abcd(data)
	x1,y1 = max(c[0],d[0]), max(a[1],d[1])
	x2,y2 = min(a[0],b[0]), min(b[1],c[1])
	rectangle = ((x2,y1), (x2,y2), (x1,y2), (x1,y1))
	# data = prune(data,rectangle)
	hull = graham_scan(data)
	fence = 0
	new = []
	for p,q in zip(hull,hull[1:]):
		new.append((p,q))
	new.append((hull[0],hull[-1]))
	for element in new:
		p1 = element[0]
		p2 = element[1]
		fence += sqrt((p1[0]-p2[0])*(p1[0]-p2[0]) + (p1[1]-p2[1])* (p1[1]-p2[1]))
	print round(fence,2)
	a = []
	for point in hull:
		a.append(get_key(point,dictionary))
	a = map(str,a)
	print ' '.join(a)
	print '\n'