def main():
	t = input()
	i = 0
	ans = 0
	tutors = {}
	ntutors = 0
	while (i < t):
		i += 1
		r = input()
		if r == 0:
			ntutors += 1
			tutors[ntutors] = []