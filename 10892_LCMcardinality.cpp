#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> D;

int GCD ( int a, int b ) {
	if ( a == 0 ) return b;
	return GCD ( b%a , a );
}

ll LCM ( ll a, ll b ) {
	return ((a*b) / (ll)GCD(a,b));
}

void divfun ( int n ) {

	int i;
	for ( i = 1 ;  i * i < n ; i++ )
		if ( n % i  == 0 )
			D.push_back(i),D.push_back(n/i);
	if ( i * i == n )
		D.push_back(i);
	sort( D.begin() , D.end() );
}

int main(){
	int n , cont;
	while ( 1 ) {
		
		scanf("%d",&n);
	
		if ( n == 0 ) break;
	
		divfun( n );

		cont = 0 ;
		for ( int i = 0 ; i < D.size() ; i++ ) {
			for ( int j = i ; j < D.size() ; j++ ) {
				if ( LCM( D[i] , D[j] ) == (ll)n )
					cont ++;
 	 		}
 		}

		printf( "%d %d\n",n,cont); 
		D.clear();		
 	} 
	
	
	return 0;
}	
