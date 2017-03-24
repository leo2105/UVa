#include <bits/stdc++.h>
#define vi vector<int>
using namespace std;

int N;

bool cross ( int mask, int x, int y ) {
    int _mask = ( 1 << (y+1) ) - 1;
    _mask = ( _mask & mask);
    _mask >>= (x);
    return ( _mask & 0 );
}

int f( int pos, int mask ) {
 //   cout << mask << endl;
    if ( mask == ((1 << (2*N)) - 1) ) return 1;

    int rpta = 0;
    for ( int i = pos ; i < 2*N - 1  ; ++i ) {
        if ( ((1 << i) & mask) == 0)
            for ( int j = i + 1 ; j < 2*N ; j += 2  )
                if ( ((1 << (j-1)) & mask) == 0  && ((1 << j) & mask) == 0 &&  !cross( mask, i , j ) ){
                    //cout << i << " " << j << endl;
                    rpta += f ( i + 1, mask | (( 1 << i ) + ( 1 << j )) );
                }
    }

    return rpta;
}

int main(){
    int mask;
   // int f[5] = {1,1};
    while ( cin >> N ) {
        cout << f ( 0, 0 ) << endl;
    } 
    return 0;
}
