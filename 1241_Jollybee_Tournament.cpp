#include <bits/stdc++.h>
using namespace std;

bool A[2000];

int main(){
	int N,x,y,id,tot,cont;
	cin>>N;
	while(N--){
		memset(A,true,2000*sizeof(bool));
		cin>>x>>y;
		cont = 0;
		for (int i = 0; i < y; ++i)
		{
			cin>>id;
			A[id-1] = false;
		}

		tot = 1<<x;
		tot /= 2;
		while(tot != 0){
			
			for(int i=0;i<tot;i++){
				if((A[i*2] == true && A[i*2+1] == false) ||
					(A[i*2] == false && A[i*2+1] == true) )
					cont++;
				A[i] = A[i*2] | A[i*2+1];
			}

			/*for (int i = 0; i < tot; ++i)
			{
				cout<<A[i]<<" ";
			}*/
			tot/=2;
			//cout<<endl;
		}
		cout<<cont<<endl;
	}
	return 0;
}
