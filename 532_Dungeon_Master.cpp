#include <bits/stdc++.h>
#define FOR(it,A) for ( auto it = A.begin() ; it != A.end() ; it++ )
#define N 35
using namespace std;

struct nodo{
	int x,y,z;
};

int L,R,C;
char M[N][N][N];
vector<nodo> Graph[N][N][N];
int dis[N][N][N];
bool vis[N][N][N];

int dx[6] = { -1, 0, 0, 0, 0, 1};
int dy[6] = { 0, -1, 0, 1, 0, 0};
int dz[6] = { 0, 0, 1, 0, -1, 0};
void BFS(nodo s){
	queue<nodo> Q;
	dis[s.x][s.y][s.z] = 0;
	vis[s.x][s.y][s.z] = true;
	Q.push(s);
	nodo u,v;

	while(!Q.empty()){
		u = Q.front();
		Q.pop();

		FOR(it,Graph[u.x][u.y][u.z]){
			v = *it;
			if(!vis[v.x][v.y][v.z]){
				vis[v.x][v.y][v.z] = true;
				dis[v.x][v.y][v.z] = dis[u.x][u.y][u.z] + 1;
				Q.push(v);
			}
		}
	}
}

bool check(int i, int j, int k){
	if( i >= 0 && i < L && j >= 0 && j < R && k >= 0 && k < C)
		return true;
	return false;
}

int main(){
	
	string S;
	nodo s,e;
	int pos1x,pos1y,pos1z,pos2x,pos2y,pos2z,aux1,aux2,aux3;
	while(true){
		cin>>L>>R>>C;

		if(L == 0 && R == 0 && C == 0)
			 break;

		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				for(int k=0;k<N;k++)
				{
					vis[i][j][k] = false;
					dis[i][j][k] = 0;
					Graph[i][j][k].clear();
				}

		for (int i = 0; i < L; ++i)
		{
			for (int j = 0; j < R; ++j)
			{
				cin>>S;
				for(int k = 0; k < C; k++)
				{
					M[i][j][k] = S[k];
					if(M[i][j][k] == 'S'){
						s.x = i;s.y = j;s.z = k;
					}

					if(M[i][j][k] == 'E'){
						e.x = i;e.y = j;e.z = k;
					}
				}	
			}
		}

		for (int i = 0; i < L; ++i)
		{
			for (int j = 0; j < R; ++j)
			{
				for (int k = 0; k < C; ++k)
				{
					for (int l = 0; l < 6 ; l++ )
					{
						aux1 = i + dx[l];
						aux2 = j + dy[l];
						aux3 = k + dz[l];

						if ( M[i][j][k] != '#' &&  check(aux1,aux2,aux3) && M[aux1][aux2][aux3] != '#' ){
							nodo n;n.x = aux1;n.y = aux2;n.z = aux3;
							Graph[i][j][k].push_back(n);
					}	}
				}	
			}
		}

		BFS(s);
		if(dis[e.x][e.y][e.z] == 0)
			cout<<"Trapped!"<<endl;
		else
			cout<<"Escaped in "<<dis[e.x][e.y][e.z]<<" minute(s)."<<endl;
	}
	return 0;
}