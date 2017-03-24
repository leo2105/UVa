#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9+7;
string B;
//int dp[];

int f ( string A, int mov ){

    cout << A << endl;
    if ( A == B ) return mov;
    if ( A.size() > 20 || A.size() < 1 ) return INF;

    int rpta = INF;
    string aux;

    for  ( int i = 0 ; i < A.size() ; i++ ){
        // Delete pos i
       /* aux = A;
        aux.erase(aux.begin() + i );
        rpta = min ( rpta, f( aux, mov + 1) );
        */
        // Insert pos i
        for ( char c = 'a' ; c <= 'z' ; c++ ){
            aux = A;
            aux.insert ( aux.begin() + i, 1, c );
            rpta = min ( rpta, f( aux , mov + 1) );
        }
        
        // Change pos i
        for ( char c = 'a' ; c <= 'z' && c != A[i] ; c++ ) {
            aux[i] = c;
            rpta = min ( rpta, f ( aux, mov + 1 ) );
            aux[i] = A[i];
        }
    }
    
    for ( char c = 'a' ; c <= 'z' ; c++ ){
            aux = A;
            aux.insert ( aux.begin() + (int)A.size(), 1, c );
            rpta = min ( rpta, f( aux , mov + 1) );
    }
    
}

int main(){
    string A;
    int aux;
    while ( cin >> A ) {
        cin >> B;    
        aux = f ( A, 0 );
        //aux += 'E';
        cout << aux << endl;
    }   
    return 0;
}
