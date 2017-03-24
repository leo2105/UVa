dp = [-1] * 1005
def f2():
	dp[0] = 1
	dp[1] = 2 
	dp[2] = 5
	for i in range(3,1005):
		dp[i] = dp[i-1] + dp[i-2] + dp[i-3] + dp[i-1]
if __name__ == '__main__':
	f2()
	while True : 
		try:
			n = int(input())
			print(dp[n])
		except EOFError:
			break
