#include <bits/stdc++.h>
#define ll long long

using namespace std;

bool sieve[1000005];
vector<int> primes;

void sieveEras () {
	int n = 1e6;
	memset ( sieve , true , sizeof sieve );

	for ( int i = 2 ; i * i <= n ; i++ )
		if ( sieve[i] ) 
			for ( int j = i * 2 ; j <= n ; j += i )
				sieve[j] = false;
		
	for ( int i = 2 ; i < n ; i++ )
		if ( sieve[i] )
			primes.push_back(i);
}

/*
int f ( int x ) {
	while ( x % 10 == 0 ) {
		x /= 10;
	}
	return (x%10);
}

void preprocces ( ) {

	int id, aux, cnt, N = 1000000;
	dp[1] = 1;
	for ( int i = 2 ; i <= 6 ; i++ ){
		aux = i , id = 0, rpta = dp[i-1];
		while ( aux != 1 ){
			if ( sieve[aux] == true ){
			
				if ( cont[aux] == 0 ){
					rpta *= aux;
					cont[aux] = 1;
				}
				aux = 1;
			}
			else{
				cnt = 0;
				while (aux % primes[id] == 0){
					aux /= primes[id];
					cnt++;
				}
	
				if ( cnt > cont[primes[id]] ){
					rpta *= (int)pow(primes[id],cnt-cont[primes[id]]);
					cont[primes[id]] = cnt;
				}
				id ++;
			}
		}
		dp[i] = f ( rpta ); // no calcula bien los dp
	}		
	
}
*/
int main(){

	sieveEras ();
	//preprocces ();
	
	int N, c2, c5, rpta;
	while ( true ) {
		scanf ( "%d" , &N );
		if ( N == 0) break;
		rpta = 1;
		c2 = c5 = 0;
		for ( int i = 2 ; i <= N ; i *= 2 ) c2++;
		for ( int i = 5 ; i <= N ; i *= 5 ) c5++;
		for ( int i = 0 ; i < c2-c5 ; i++ ) rpta = ( rpta * 2 ) % 10;
		for ( int i = 3 ; i <= N ; i *= 3 ) rpta = ( rpta * 3 ) % 10;
		for ( int i = 3 ; i < primes.size() ; i++ ) {	
			if ( primes[i] > N ) break;
			for ( long long j = primes[i] ; j <= N ; j *= primes[i] )
				rpta = ( rpta * primes[i] ) % 10;
		}
		printf("%d\n",rpta);
	}
	return 0;
}
