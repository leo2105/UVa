#include <bits/stdc++.h>
#define mod ('z'-'a'+1)
using namespace std;


void f(string A, int x){
	for(int i=0;i<A.size();i++){
		if('a' <= A[i] && A[i] <= 'z')
			A[i] = 'a' + (A[i]-'a' + x%mod + mod)%mod;
		if('A' <= A[i] && A[i] <= 'Z')
			A[i] = 'A' + (A[i]-'A' + x%mod + mod)%mod;		
	}
	cout<<A<<endl;
}

int main(){
	string A;
	int x;
	
	while(true){
		cin>>x;
		getchar();
		getline(cin,A);
		if(x == 0) break;
		//cout<<x<<endl<<A<<endl;
		f(A,x);
	}
	
	return 0;
}
