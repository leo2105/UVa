#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

const int N = 1e5;
typedef vector<int> BigInt;

int n,dp[N];

void Set(BigInt &a){
	while (a.size() > 1 && a.back() == 0) a.pop_back();
}


ll f(int sum){
	if ( sum == n ) return 1LL;
	if ( sum > n ) return 0LL;

	if( dp[sum] != -1) return dp[sum];

	return ( dp[sum] = f(sum+1) + f(sum+2) + f(sum+3) + f(sum+1));
}

int main(){
	while( cin >> n ){
		memset ( dp , -1 , sizeof dp );
		cout << f( 0 ) << endl;
	}
	return 0;
}
