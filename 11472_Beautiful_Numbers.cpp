#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int N,M;
int dp[100 + 5][(1<<10) + 5][10 + 5];

int search(int d, int bitMask, int lastDigit)
{
	if (d > M) 
		return 0;

	if (dp[d][bitMask][lastDigit] != -1)
		return dp[d][bitMask][lastDigit];	

	int cont = 0;
	
	if (bitMask == ((1<<N) - 1))
		cont++;

	for (int next = lastDigit - 1; next <= lastDigit + 1; next+=2)
	{
		if (next < 0 || next >= N)
			continue;
		
		cont += search(d + 1, bitMask | (1 << next), next);
		cont %= MOD;
	}

	return dp[d][bitMask][lastDigit] = cont;
}


int solve()
{
	memset(dp,-1,sizeof(dp));
	int total = 0;
	
	for(int firstDigit = 1; firstDigit <= N-1; ++firstDigit)
	{
		total += search(1, 1 << firstDigit, firstDigit);
		total %= MOD;
	}
	return total;
}
int main(){
	int T;
	cin >> T;
	while ( T-- ) {
		cin >> N >> M;
		cout << solve() << endl;
	}
	return 0;
}
