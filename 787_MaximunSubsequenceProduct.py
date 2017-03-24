A = [-1] * 105
aux = 999999*-1

def kadane():
	act_min = act_max = prev_max = prev_min = ans = int(A[0])
	for i in range( 1 , len( A ) - 1 ):
		act_max = max ( prev_max * int(A[i]) , prev_min * int(A[i]) , int(A[i]) )
		act_min = min ( prev_max * int(A[i]) , prev_min * int(A[i]) , int(A[i]) )
		ans = max ( ans , act_max )
		prev_max = act_max
		prev_min = act_min
	print ( ans )
if __name__ == '__main__':
	i = 0
	while True : 
		
		try:
			n = (input())
			A = n.split()
			kadane () 			
		except EOFError:
			break
