#include <bits/stdc++.h>
#define FOR(it,A) for (auto it = A.begin() ; it != A.end() ; it++)
#define N 1005
#define dim 5
using namespace std;

struct nodo{
	int x,y;
};

int dx[8] = {-2,-1,1,2,2,1,-1,-2};
int dy[8] = {-1,-2,-2,-1,1,2,2,1};

vector<nodo> G[N][N];
char A[N][N];
bool vis[N][N];
int dis[N][N];

bool checkMatrix(){

	if(A[0][0] == '0' || A[1][1] == '0' || A[2][2] != ' ' || A[3][3] == '1' || A[4][4] == '1')
		return false;

	for (int i = 0; i < dim; ++i)
	{
		for (int j = 0; j < dim; ++j)
		{
			if( i > j && A[i][j] == '1'){
				return false;
			}

			if( j > i && A[i][j] == '0'){
				return false;
			} 

		}
	}

	return true;
}

bool check(int x, int y){
	if( x >= 0 && x < dim && y >= 0 && y < dim)
		return true;
	return false;
}

int BFS(nodo s){
	queue<nodo> Q;
	//vis[s.x][s.y] = true;
	dis[s.x][s.y] = 0;
	nodo u,v;
	Q.push(s);
	while(!Q.empty()){
		u = Q.front();
		Q.pop();
		FOR(it,G[u.x][u.y]){
			v = *it;
			if (!vis[v.x][v.y])
			{
				//vis[v.x][v.y] = true;
				dis[v.x][v.y] = dis[u.x][u.y] + 1;
				if(checkMatrix())
					return dis[v.x][v.y];
				Q.push(v);
			}
		}
	}
}

int main(){
	int T,Jx,Jy,aux1,aux2;
	char S[100];
	scanf("%d",&T);
	getchar();
	while(T--){

		for (int i = dim; i--;)
		{
			for (int j = dim; j--;)
			{
				dis[i][j] = -1;
				vis[i][j] = false;
				G[i][j].clear();
			}
		}
		

		for (int i = 0; i < 5; i++)
		{
			gets(S);
			for (int j = 0 ; j < 5 ; j++ )
			{
				A[i][j] = S[j];
				if( A[i][j] == ' ' ){
					Jx = i;
					Jy = j;
				}
			}
		}

		for (int i = dim; i--;)
		{
			for (int j = dim; j--;)
			{
				for (int k = 8; k--; )
				{
					aux1 = i + dx[k];
					aux2 = j + dy[k];

					if( check(aux1,aux2)){
						nodo aux; aux.x = aux1; aux.y = aux2;
						G[i][j].push_back(aux);
					}
				}
			}
		}

		nodo n1;
		n1.x = Jx; n1.y = Jy;
		cout<< "La cantidad de pasos es: "<<BFS(n1)<<endl;

	}
	return 0;
}