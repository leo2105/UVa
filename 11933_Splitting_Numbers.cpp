#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ll N,sum1,sum2,x;
	bool flag;

	while(true){
		cin>>N;
		if(N == 0)
			break;

		sum1=0LL;sum2=0LL;
		flag = true;
		for (int i = 0; i < 32; ++i)
		{
			x = (1LL)<<i;
			if( (x&N) != 0LL ){
				if(flag){
					sum1+=x;
					flag = false;
				}else{
					sum2+=x;
					flag = true;
				}
			}
		}
		cout<<sum1<<" "<<sum2<<endl;
	}
	return 0;
}