
def GCD (a , b) : 
	if b == 0 : 
		return a
	return GCD ( b,a%b)

if __name__ == '__main__':
	
	while True : 
		n = int(input())
		if n == 0 : 
			break
		rpta = 1;
		for i in range(1,n+1):
			rpta = ((rpta * i) / GCD (rpta,i))
			if rpta % 10 == 0 :
				rpta /= 10
		print(rpta)
