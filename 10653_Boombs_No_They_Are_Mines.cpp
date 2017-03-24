#include <bits/stdc++.h>
#define FOR(it,A) for(typeof A.begin() it = A.begin() ; it != A.end() ; it++)
#define N 1000005
using namespace std;

vector<int> G[N];
bool vis[N];
int dis[N];
bool pos[N];
int R,C,F;

int dx[4] = { -1 , 0 , 1 , 0};
int dy[4] = { 0 , 1 , 0 , -1};

/*void BFS(int s){

	queue<int> Q;
	vis[s] = true;
	dis[s] = 0;
	Q.push(s);
	int u,v;
	
	while(!Q.empty()){
		u = Q.front();
		Q.pop();

		FOR(it,G[u]){
			v = (*it);
			if(!vis[v] && pos[v]){
				vis[v] = true;
				dis[v] = dis[u] + 1; 
				Q.push(v);
			}
		}
	}
}*/

void BFS(int source){
    queue<int> Q;
    dis[source] = 0;
    vis[source] = true;
    Q.push(source);
    
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        FOR(it,G[u]){
            int v=*it;
            if(!vis[v]){
                vis[v]=true;
                dis[v] = dis[u]+1;
                Q.push(v);
            }
        }
    }
}

bool check(int x, int y){
	if(x >=  0 &&  y >= 0 && x < R && y < C)
		return true;
	return false;
}

int main(){

	int row,n,f,x;
	int x1,y1,x2,y2,pos1x,pos1y,pos2x,pos2y;

	while(true){

		cin>>R>>C;
		if(R == 0 && C == 0) break;
		
		for (int i = 0; i < N; ++i)
		{	
			pos[i] = true;
			vis[i] = false;
			dis[i] = 0;
			G[i].clear();
		}

		cin>>F;

		for (int i = 0; i < F; ++i)
		{
			scanf("%d %d",&f,&n);
			for (int j = 0; j < n; ++j)
			{
				scanf("%d",&x);
				pos[f*C+x] = false;
			}
		}

		cin>>x1>>y1;
		cin>>x2>>y2;

		for (int i = 0; i < R; ++i)
		{
			for (int j = 0; j < C; ++j)
			{
				for(int k = 0; k < 4; k++ )
				{
					pos1x = i;
					pos1y = j;
					pos2x = i+dx[k];
					pos2y = j+dy[k];

					if (check( pos2x , pos2y ) && pos[pos1x * C + pos1y] && pos[ (pos2x)*C + (pos2y) ])
					{
						G[pos1x*C+pos1y].push_back((pos2x)*C + (pos2y));
					}
				}
			}
		}
		//cout<<(x1*C+y1)<<" "<<(x2*C+y2)<<endl;
		BFS(x1 * C + y1);

		/*for (int i = 0; i < R*C; ++i)
		{
			cout<<dis[i];
			cout<<endl;
		}*/
		cout<<dis[x2 * C + y2]<<endl;
	}

	return 0;
}