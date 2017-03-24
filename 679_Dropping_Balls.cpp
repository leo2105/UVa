#include <bits/stdc++.h>
using namespace std;

//vector<int> rpta;

int inv(int mask, int d){
	int sum = 0;
	for(int  i = 0; i < d-1; i++){
		if(mask & (1<<i))
			sum += (1<<(d-i-2));
	}
	return sum;
}

int f(int d, int a){
	//for(int mask = 0; mask < (a); mask++){
		return ((1 << (d-1)) + inv(a-1, d));
	//}
}	
int main(){
	int T,d,a;
	cin>>T;
	while(T--){
		cin>>d>>a;
		//for(int i=0;i<6;i++) cout<<rpta[i]<<" "; cout<<endl;
		cout<<f(d,a)<<endl;
	}
	cin>>T;
	return 0;
}
