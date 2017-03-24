#include <bits/stdc++.h>
using namespace std;

int A[20005];
int main(){
	int T, N, rpta, sum;
	cin >> T;
	while ( T-- ) {
		cin >> N;
		for ( int i = 0 ;  i < N - 1 ; i++ ) cin >> A[i];
		sum = 0, rpta = -1;
		for ( int i = 0 ;  i < N - 1 ; i++ ){
			sum += A[i];
			if ( sum > rpta )
				rpta = sum;
			sum = max ( sum , 0 ); 
		}	
		cout << rpta << endl;
	}	
	return 0;
}
