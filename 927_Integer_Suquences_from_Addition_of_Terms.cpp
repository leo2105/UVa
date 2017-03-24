#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll f_a( vector<int> V, int a){
	ll acum=0LL;
	for(int i=0;i<(int)V.size();i++)
		acum += (V[i]*pow(a,i));
	return acum;
}

int main(){
	int T,a,b,n,d,k,cont;
	int sum;
	cin>>T;
	vector<int> V;
	while(T--){
		V.clear();		
		cin>>n;
		for(int i=0;i<n+1;i++){
			cin>>b;
			V.push_back(b);
		}	

		cin>>d>>k;

		sum = 0;
		cont = 1;
		
		while(sum < k){
			sum += d*cont;
			cont++;
		}

		cout<<f_a(V,cont-1)<<endl;
	}	
	return 0;
}
