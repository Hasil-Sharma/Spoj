def main():
	string = raw_input()
	while(string != "0"):
		num = string[2:-3]
		den1 = pow(10,len(num))
		den2 = 10*den1
		num1 = int(num)
		num2 = num + num[-1]
		num2 = int(num2)
		x1 = num2 - num1
		y1 = den2 - den1
		d = gcd(x1,y1)
		x1 = x1/d
		y1 = y1/d
		den2 = pow(den1,2)
		num2 = num + num
		num2 = int(num2)
		x2 = num2 - num1
		y2 = den2 - den1
		d = gcd(x2,y2)
		x2 = x2/d
		y2 = y2/d
		if(y1 < y2):
			print str(x1)+"/"+str(y1) 
		else:
			print str(x2)+"/"+str(y2)
		string = raw_input()

def gcd(x,y):
	return x if y == 0 else gcd(y,x%y)

if __name__ == '__main__':
	main()