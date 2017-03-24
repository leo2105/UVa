#include <bits/stdc++.h>
using namespace std;
const int N = 105;
const int _oo = (1<<31);
int dp[N][N], S[N][N], arr[N], n;

int kadane ( int y , int x ){

	for ( int i = 0 ; i < n ; i++ ){
		arr[i] = S[y+1][i] - S[x][i];
	}
	int rpta,act;
	rpta = arr[0];
	act = max ( arr[0] , 0 );
	for ( int i = 1 ; i < n ; i++ ){
		act = max ( act + arr[i] , arr[i] );
		rpta = max ( rpta , act );
	}
	return rpta;
} 
int main(){
	
	int rpta;
	while ( scanf( "%d",&n ) == 1 ){
		
		memset ( dp , 0 , sizeof dp );
		memset ( S , 0 , sizeof S );
		memset ( arr , 0 , sizeof arr ); 
		rpta = _oo;
		for ( int i = 0 ; i < n ; i++ )
			for ( int j = 0 ; j < n ; j++ )
				scanf( "%d" , &dp[i][j]);
		for ( int i = 0 ; i < n ; i++ ){
			for ( int j = 0 ; j < n ; j++ ){
				if( i == 0 ) S[i+1][j] = dp[i][j];
				else S[i+1][j] = S[i][j] + dp[i][j];
			}
		}	
	
		for ( int i = 0 ; i < n ; i++ ){
			for ( int j = 0 ; j <= i ; j++ ){
				rpta = max ( rpta , kadane(i,j));
			}
		}

		printf ( "%d\n", rpta );
	}	
	
	return 0;
}	
