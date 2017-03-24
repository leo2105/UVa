#include <bits/stdc++.h>
#define FOR(it,A) for(typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define N 100

using namespace std;
vector<int> Graph[N];
int d[N];
bool vis[N];

void BFS(int source){
    queue<int> Q;
    d[source] = 0;
    vis[source] = true;
    Q.push(source);
    
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        FOR(it,Graph[u]){
            int v=*it;
            if(!vis[v]){
                vis[v]=true;
                d[v] = d[u]+1;
                Q.push(v);
            }
        }
    }
}

bool check(int a,int b){
	if(a < 0 || a >= 8 || b < 0 || b >= 8)
		return false;
	return true;
}

int main()
{
	char c1,c2;
	int n1,n2;

   	for(int i=0;i<8;i++){
   		for(int j=0;j<8;j++){
   			if(check(i-2,j-1)){
   				Graph[i*8+j].push_back((i-2)*8+j-1);
   			}
   			if(check(i-1,j-2)){
   				Graph[i*8+j].push_back((i-1)*8+j-2);

   			}
   			if(check(i+1,j-2)){
   				Graph[i*8+j].push_back((i+1)*8+j-2);

   			}
   			if(check(i+2,j-1)){
   				Graph[i*8+j].push_back((i+2)*8+j-1);

   			}
   			if(check(i+2,j+1)){
   				Graph[i*8+j].push_back((i+2)*8+j+1);

   			}
   			if(check(i+1,j+2)){
   				Graph[i*8+j].push_back((i+1)*8+j+2);

   			}
   			if(check(i-1,j+2)){
   				Graph[i*8+j].push_back((i-1)*8+j+2);

   			}
   			if(check(i-2,j+1)){
   				Graph[i*8+j].push_back((i-2)*8+j+1);
   			}
   		}
   	}

   	int aux,aux2;
   	while(scanf("%c%d %c%d",&c1,&n1,&c2,&n2) == 4){
   		
   		for(int i=0;i<N;i++){
   			d[i] = 0; vis[i] = 0;
   		}

   		aux = (n1-1)*8 + (c1-'a');
   		aux2 = (n2-1)*8 + (c2-'a');
   		BFS(aux);
   		for(int i=0;i<64;i++){
   		if(vis[i]==false)
   			cout<<"hola"<<endl;
   	}
   		printf("To get from %c%d to %c%d takes %d knight moves.\n",c1,n1,c2,n2,d[aux2]);
   		getchar();
   	}
}
