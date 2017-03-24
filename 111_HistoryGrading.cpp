#include <bits/stdc++.h>
using namespace std;

int A[25], B[25];

void LCS(int n){

    int M[25][25];
    for ( int i = 0 ; i <= n ; i++ ) {
        for ( int j = 0 ; j <= n ; j++ ) {
            if ( i == 0 || j == 0 ) M[i][j] = 0;
            else{
                if ( A[i-1] == B[j-1] ) M[i][j] = M[i-1][j-1] + 1;
                else M[i][j] = max ( M[i-1][j], M[i][j-1]); 
            }
        }
    }
    cout << M[n][n] << endl;
}
int main(){
    int n = 0, cont;
    string S, aux;
    
    while( getline(cin, S)){
        if ( S.size() == 1 ){
            cont = 0;
            n = S[0] - '0';
            getline(cin, S);
         
            for ( int i = 0 ; i < S.size() ; i++ ){
                if ( S[i] == ' ' ) {
                    if ( aux.size() == 1) A[aux[0] - '0' - 1] = cont++;
                    else A[(aux[1] - '0') + 10 * (aux[0] - '0') - 1] = cont++;
                    aux.clear();
                }
                else aux += S[i];
            }
            if ( aux.size() == 1) A[aux[0] - '0' - 1] = cont;
            else A[(aux[1] - '0') + 10 * (aux[0] - '0') - 1] = cont;
            aux.clear();
           // cout << n << endl;
           // for ( int i = 0 ; i < n ; i++ ) cout << A[i] << " ";
           // cout << endl;
        }    
        else if( S.size() == 2){
      
            cont = 0;
            n = (S[1] - '0') + 10 * (S[0] - '0');
            getline(cin, S);
           
            for ( int i = 0  ; i < S.size() ; i++ ){
                if ( S[i] == ' ' ) {
                    if ( aux.size() == 1) A[aux[0] - '0' - 1] = cont++;
                    else A[(aux[1] - '0') + 10 * (aux[0] - '0') - 1] = cont++;
                    aux.clear();
                }
                else aux += S[i];
            }
            if ( aux.size() == 1) A[aux[0] - '0' - 1] = cont;
            else A[(aux[1] - '0') + 10 * (aux[0] - '0')] = cont;
            aux.clear();
            //cout << n << endl;
            //for ( int i = 0 ; i < n ; i++ ) cout << A[i] << " ";
            //cout << endl;

        }else {
            cont = 0;
           
            for ( int i = 0  ; i < S.size() ; i++ ){
                if ( S[i] == ' ' ) {
                    if ( aux.size() == 1) B[aux[0] - '0' - 1] = cont++;
                    else B[(aux[1] - '0') + 10 * (aux[0] - '0') - 1] = cont++;
                    aux.clear();
                }
                else aux += S[i];
            }
            if ( aux.size() == 1) B[aux[0] - '0' - 1] = cont;
            else B[(aux[1] - '0') + 10 * (aux[0] - '0') - 1] = cont;
            aux.clear();

            LCS(n);
            //for ( int i = 0 ; i < n ; i++ ) cout << B[i] << " ";
            //cout << endl;  
        }
        
        
    }
    return 0;
}
