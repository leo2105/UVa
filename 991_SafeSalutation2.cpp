#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll C[15];
int N;
void CatalanNumber(){
    C[0] = 1;
    for ( int i = 1 ; i < 12 ; i++ )
        C[i] = (4*i-2) * C[i-1] / (i+1);
}
int main(){
    CatalanNumber();
    cin >> N;
    cout << C[N];
    bool flag = true;
    while ( cin >> N ){
        if ( flag ) cout << endl; 
        flag = false;
        cout << endl << C[N] << endl;
    }
    return 0;
}
