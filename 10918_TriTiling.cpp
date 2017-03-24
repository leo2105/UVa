#include <bits/stdc++.h>
using namespace std;
const int N=35;
int dp[N][(1<<3)];
int n;

int tri(int pos, int mask){
	
		
	
	if( pos == n)
		return (mask == 0);
	if( dp[pos][mask] != -1) return dp[pos][mask];

	int cont = 0;
	
	if( mask == 0 )
		cont = tri( pos + 1 , 1 ) + tri( pos + 1 , 4) + tri( pos + 2 , 0 );
	if( mask == 1 )
		cont = tri( pos + 1 , 0 ) + tri( pos + 1 , 6 );	
	if( mask == 2 )
		cont = tri( pos + 1 , 5 );
	if( mask == 3 )
		cont = tri( pos + 1 , 4 );
	if( mask == 4 )
		cont = tri( pos + 1 , 0 ) + tri( pos + 1 , 3 );
	if( mask == 5 )
		cont = tri( pos + 1 , 2);
	if( mask == 6)
		cont = tri( pos + 1 , 1);
	dp[pos][mask] = cont;
	return cont;
}

int main(){
	while(1){
		cin>>n;
		if(n==-1) break;
		memset( dp , -1 , sizeof dp);	
		n&1 ? cout<<0<<endl : cout<<tri(0,0)<<endl;
	}
	return 0;
}
