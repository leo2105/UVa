#include <bits/stdc++.h>
#define f(i,x,y) for (int i = x; i < y; i++)
#define fd(i,x,y) for(int i = x; i>= y; i--)
#define FOR(it,A) for(typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define vint vector<int>
#define ll long long
#define clr(A,x) memset(A, x, sizeof A)
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define fst first
#define snd second
#define ones(x) __builtin_popcount(x)
#define eps (1e-9)
#define NOsync ios_base::sync_with_stdio(0)
#define oo (1<<30)
#define OO (1LL<<60)
#define N 1005
using namespace std;

int cant=1;
int rpta=0;
bool vis[N];
int grafo[N][N];

void dfs(int s){

	vis[s] = true;
	for(i,0,N){
		if(grafo[s][i] != 0 && !vis[i])
			cout<<i<<" ";
		dfs(i);
	}
}

int main(){
	
	int nodos,aristas,source,a,b;
	f(i,0,N)
		f(j,0,N)
			grafo[i][j]=0;
    
    cout<<"Ingresar la cantidad de aristas: ";
    cin>>aristas;

    f(i,0,aristas){
        cin>>a>>b;// Ingresar los nodos unidos
        grafo[a][b]=1; // Nodo a apunta a Nodo b
        grafo[b][a]=1; // Nodo b apunta a Nodo a
    }

    int inicio;    
    inicio = 0;    
    cout<<inicio<<" ";

    // 0 es el nodo de raiz
    dfs(inicio);

	return 0;
}