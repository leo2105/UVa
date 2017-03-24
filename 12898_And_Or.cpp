#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	ll A,B,x,sum1,sum2;
	int T;
	int cont=1;
	bool flag1,flag2;
	cin>>T;

	while(cont<=T){
		cin>>A>>B;
		// OR
		sum1 = 0LL;
		sum2 = 0LL;
		cout<<"Case "<<cont<<": ";
		for (int i = 0; i < 63; i++)
		{
			x = (1LL)<<i;
			
			if( (x & A) != (0LL) ) flag1 = true;
			else flag1 = false;

			if( (x & B) != (0LL) ) flag2 = true;
			else flag2 = false;

			if(flag2 || flag1 || B-A >= x) sum1+=x;

			if(flag1 == true && flag2 == true && B-A <= x) sum2+=x;
		}
		cout<<sum1<<" "<<sum2<<endl;
		cont++;
	}
		


	return 0;
}