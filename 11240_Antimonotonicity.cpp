#include <bits/stdc++.h>
using namespace std;

int func(int a,int b,bool flag){
	if(flag)
		return (a>b);
	else
		return (a<b);
}

int main(){
	int T,N,cont,may,a,sum,ind;
	vector<int> A,rpta;
	scanf("%d",&T);
	while(T--){
		A.clear();
		rpta.clear();
		scanf("%d",&N);
		if(N == 1){
			cout<<1<<endl;continue;
		}

		for(int i=0;i<N;i++){
			scanf("%d",&a);
			A.push_back(a);	
		}
		//may = 0;
		/*for(int i=1;i<N;i++){
			cont = 1;
			flag = true;
			while(func(A[i-1],A[i],flag)){
				cont++;
				i++;
				flag  = (not flag);
				if(i == N) break;
			}
			//if(cont > may) may = cont;
			if(cont>1) may+=cont;
		}
		if(may == 0) cout<<1<<endl;
		else
		cout<<may<<endl;*/
		for(int i=1;i<N;i++){
			if(A[i-1]<A[i]) rpta.push_back(0);
			else rpta.push_back(1);
		}
		cont=0;
		ind = 1;
		sum = 0;
		for(int i=0;i<rpta.size();i++){
			if(rpta[i] == ind ){
				cont++;
				ind = (ind == 0 ? 1 : 0);
				continue;
			}
			sum += cont;
			cont = 0;
		}
		sum += cont;
		cout<<(sum+1)<<endl;
	}
	return 0;
}
