#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

struct line{
	int s,f;
};

bool ordenar(line A, line B){
	if(A.s < B.s) return true;
	else if(A.s == B.s && A.f <= B.f) return true;
	return false;
}

bool overlap(line a,line b){
	return (a.f >= b.s && a.s <= b.f);
}

line comp;
line act;

int main(){
	int T,M,a,b,x,y,d,j;
	scanf("%d",&T);
	while(T--){
		vector<line> V;
		vector<int> X,Y;
		scanf("%d",&M);
		
		while(true){
			scanf("%d %d",&a,&b);
			if(a == 0 && b == 0) break;
			
			line x;
			x.s = a;
			x.f = b;
			V.push_back(x);	
		}
		
		sort(V.begin(),V.end(),ordenar);	
	
		comp.s = 0;
		comp.f = M;

		x = 0;
		d = 0;
		
		for( j=0; j<(int)V.size();j++)
			if(overlap(comp,V[j]) && V[j].s <= x && x <= V[j].f){
				X.push_back(j);act = V[j];d = V[j].f-x;break;
			}
		j++;
		for( ; j < (int)V.size() ; j++){
			if(overlap(comp,V[j]) ){
				if(V[j].s <= x  && x <= V[j].f){
					if(V[j].f - x > d){
						d = V[j].f - x;
						X.pop_back();
						X.push_back(j);
						act = V[j];
					}
				}else{
					if( V[j].f > act.f && V[j].s <= act.f ){
						x = act.f;
						d = V[j].f - x;
						X.push_back(j);
						act = V[j];
					}
				}
			}
			if(V[X[X.size()-1]].f >= M) break; 
		}

                if(act.f < M){
			printf("0\n\n");continue;
		}

		printf("%d\n",(int)X.size());

		for(int i=0;i<X.size();i++)
			printf("%d %d\n",V[X[i]].s,V[X[i]].f);
		printf("\n");
	
	}

	return 0;
}
