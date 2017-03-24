#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	int T;
	ll N,K,a;
	vector<int> V;	
	vector<int> F;
	cin>>T;
	
	while(T--){
		cin>>N>>K;
		V.clear();
		for(int i=0;i<K;i++){
			cin>>a;
			V.push_back(a);}
		F.push_back(V[0]);
		for(int i=(int)V.size()-1;i>0;i--)
			F.push_back();	
	}
	return 0;
}
