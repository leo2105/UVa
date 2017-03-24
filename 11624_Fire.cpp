#include <bits/stdc++.h>
#define FOR(it,A) for ( typeof A.begin() it = A.begin() ; it != A.end() ; it++ ) 
#define N 1005
#define oo (1<<30)
using namespace std;

struct nodo{
	int x,y;
};

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

vector<nodo> G[N][N];
char A[N][N];
bool visJ[N][N];
int disJ[N][N];
bool visF[N][N];
int disF[N][N];
int R,C;

void BFS_J(nodo s){
	queue<nodo> Q;
	Q.push(s);
	disJ[s.x][s.y] = 0;
	visJ[s.x][s.y] = true;
	nodo u,v;

	while(!Q.empty()){
		u = Q.front();
		Q.pop();

		FOR(it,G[u.x][u.y]){
			v = *it;
			if(!visJ[v.x][v.y]){
				visJ[v.x][v.y] = true;
				disJ[v.x][v.y] = disJ[u.x][u.y] + 1;
				Q.push(v);
			}
		}
	}
}

void BFS_F(nodo s){
	queue<nodo> Q;
	Q.push(s);
	disF[s.x][s.y] = 0;
	visF[s.x][s.y] = true;
	nodo u,v;

	while(!Q.empty()){
		u = Q.front();
		Q.pop();

		FOR(it,G[u.x][u.y]){
			v = *it;
			if(!visF[v.x][v.y]){
				visF[v.x][v.y] = true;
				disF[v.x][v.y] = disF[u.x][u.y] + 1;
				Q.push(v);
			}
		}
	}
}

bool check(int x, int y){
	if( x >= 0 && x < R && y >= 0 && y < C)
		return true;
	return false;
}

int main(){

	int T,aux1,aux2,Jx,Jy,Fx,Fy;
	char S[N];
	scanf("%d",&T);

	while(T--){

		scanf("%d %d",&R,&C);

		for (int i = R; i--;)
		{
			for (int j = C; j--;)
			{
				disJ[i][j] = -1;
				visJ[i][j] = false;
				disF[i][j] = -1;
				visF[i][j] = false;
				G[i][j].clear();
			}
		}

		
		for (int i = R; i--;)
		{
			scanf("%s",S);
			for (int j = C; j--;)
			{
				A[i][j] = S[j];
				if( A[i][j] == 'J' ){
					Jx = i;
					Jy = j;
				}
				if( A[i][j] == 'F' ){
					Fx = i;
					Fy = j;
				}
			}
		}

		for (int i = R; i--;)
		{
			for (int j = C; j--;)
			{
				for (int k = 4; k--; )
				{
					aux1 = i + dx[k];
					aux2 = j + dy[k];

					if( A[i][j] != '#' && check(aux1,aux2) && A[aux1][aux2] != '#' ){
						nodo aux; aux.x = aux1; aux.y = aux2;
						G[i][j].push_back(aux);
					}
				}
			}
		}

		nodo n1,n2;
		n1.x = Jx; n1.y = Jy;
		n2.x = Fx; n2.y = Fy;
		
		BFS_J(n1);
		BFS_F(n2);

		int rpta = oo;
		bool flag = false;

		for(int i=0;i<C;i++){
			if(disJ[0][i] != -1 && 
			( ( disJ[0][i] < disF[0][i] ) ||  ( disF[0][i] == -1 ) )){
				flag = true;
				if( disJ[0][i] < rpta)
					rpta = disJ[0][i]; 
			}
		}

		
		for(int i=0;i<C;i++){
			if ( disJ[R-1][i] != -1 && 
			( ( disJ[R-1][i] < disF[R-1][i] ) ||  ( disF[R-1][i] == -1 ) ) ){
				flag = true;
				if( disJ[R-1][i] < rpta)
					rpta = disJ[R-1][i]; 
			}
		}


		for(int i=0;i<R;i++){
			if(disJ[i][0] != -1 && 
				( ( disJ[i][0] < disF[i][0] ) ||  ( disF[i][0] == -1 ) ) ){
				flag = true;
				if( disJ[i][0] < rpta)
					rpta = disJ[i][0]; 
			}
		}

		for(int i=0;i<R;i++){
			if(disJ[i][C-1] != -1 && 
			( ( disJ[i][C-1] < disF[i][C-1] ) ||  ( disF[i][C-1] == -1 ) ) ){
				flag = true;
				if(disJ[i][C-1] < rpta)
					rpta = disJ[i][C-1]; 
			}
		}		

		if(!flag)
			printf("IMPOSSIBLE\n");
		else
			printf("%d\n",(rpta+1));

	}
	return 0;
}
/*
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
 
#define INF_MAX 2147483647
#define INF_MIN -2147483647
#define pi acos(-1.0)
#define N 1000000
#define LL long long
 
#define For(i, a, b) for ( int i = (a); i < (b); i++ )
#define Fors(i, sz) for ( size_t i = 0; i < sz.size (); i++ )
#define Set(a, s) memset (a, s, sizeof (a))
 
using namespace std;
 
struct state {
    int x;
    int y;
    int c;
 
    state (int p, int q, int r) {
        x = p;
        y = q;
        c = r;
    }
 
    state () { }
} a;
 
int row, col;
char matrix [1000 + 5] [1000 + 5];
int cost_joe [1000 + 5] [1000 + 5];
int cost_fire [1000 + 5] [1000 + 5];
int dr [] = {-1, 0, 1, 0};
int dc [] = {0, 1, 0, -1};
 
void bfs_for_joe (int r, int c)
{
    queue <state> q;
    cost_joe [r] [c] = 0;
    q.push(state (r, c, 0));
 
    while ( !q.empty() ) {
        a = q.front(); q.pop();
 
        for ( int i = 0; i < 4; i++ ) {
            int nx = a.x + dr [i];
            int ny = a.y + dc [i];
            if ( nx >= 0 && nx < row && ny >= 0 && ny < col && matrix  [nx] [ny] != '#' && cost_joe [nx] [ny] == INF_MAX ) {
                cost_joe [nx] [ny] = a.c + 1;
                q.push(state (nx, ny, a.c + 1));
            }   
        }
    }
}
 
void bfs_for_fire ()
{
    queue <state> q;
 
    for ( int i = 0; i < row; i++ ) {
        for ( int j = 0; j < col; j++ ) {
            if ( matrix [i] [j] == 'F' ) {
                cost_fire [i] [j] = 0;
                q.push(state (i, j, 0));
            }
        }
    }
 
    while ( !q.empty() ) {
        a = q.front(); q.pop();
 
        for ( int i = 0; i < 4; i++ ) {
            int nx = a.x + dr [i];
            int ny = a.y + dc [i];
            if ( nx >= 0 && nx < row && ny >= 0 && ny < col && matrix  [nx] [ny] != '#' && cost_fire [nx] [ny] > a.c + 1) {
                cost_fire [nx] [ny] = a.c + 1;
                q.push(state (nx, ny, a.c + 1));
            } 
        }
    }
}
 
void reset ()
{
    for ( int i = 0; i < 1005; i++ ) {
        for ( int j = 0; j < 1005; j++ )
            cost_joe [i] [j] = cost_fire [i] [j] = INF_MAX;
    }
}
 
 
int main(int argc, char** argv)
{     
    int testCase;
    scanf ("%d", &testCase);
 
    while ( testCase-- ) {
        scanf ("%d %d", &row, &col);
 
        for ( int i = 0; i < row; i++ ) scanf ("%s", matrix [i]);
 
        reset ();
 
        for ( int i = 0; i < row; i++ ) {
            for ( int j = 0; j < col; j++ ) {
                if ( matrix [i] [j] == 'J' ) {
                    bfs_for_joe (i, j);
                    i = row;
                    j = col;
                }
            }
        }
 
        bfs_for_fire();
 
        int minimum_escape_time = INF_MAX;
 
        // 1st & last row
        for ( int i = 0; i < col; i++ ) {
            if ( cost_fire [0] [i] > cost_joe [0] [i] ) minimum_escape_time = min (minimum_escape_time, cost_joe [0] [i]);
            if ( cost_fire [row - 1] [i] > cost_joe [row - 1] [i] ) minimum_escape_time = min (minimum_escape_time, cost_joe [row - 1] [i]);
        }
 
        // 1st & last col
        for ( int i = 0; i < row; i++ ) {
            if ( cost_fire [i] [0] > cost_joe [i] [0] ) minimum_escape_time = min (minimum_escape_time, cost_joe [i] [0]);
            if ( cost_fire [i] [col - 1] > cost_joe [i] [col - 1] ) minimum_escape_time = min (minimum_escape_time, cost_joe [i] [col - 1]);
        }
 
        if ( minimum_escape_time == INF_MAX ) printf ("IMPOSSIBLE\n");
        else printf ("%d\n", minimum_escape_time + 1);
 
    }
 
    return 0;
}
*/