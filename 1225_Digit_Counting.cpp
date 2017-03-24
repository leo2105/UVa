#include <bits/stdc++.h>
using namespace std;

int dp[10005][10];
int N,T;

void dfs(int s,int ant){
	if(s > 13)
		return;
	cout<<s<<endl;
	int aux,aux1,aux2;
	aux = s;
	for(int i=0;i<10;i++)
		dp[s][i] += dp[ant][i];

	while(aux > 0){
		aux1 %= 10;
		aux /= 10;
		dp[s][aux1]++;
	}

	for(int i=0;i<10;i++){
		aux2 = s*10+i;
		dfs(aux2,s);
	}
}

int main(){
	scanf("%d",&T);
	int aux;
	for (int i = 1; i < 10005; ++i)
	{	
		for (int j = 0; j < 10; ++j)
			dp[i][j] += dp[i-1][j];
		aux = i;
		while(aux > 0){
			dp[i][aux%10]++;
			aux /= 10;
		}
	}

	while(T--){
		scanf("%d",&N);
		for (int i = 0; i < 9; ++i)
			printf("%d ",dp[N][i]);
		printf("%d",dp[N][9]);
		printf("\n");
	}

	
	
	
	return 0;
}