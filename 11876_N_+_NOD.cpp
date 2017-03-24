#include <bits/stdc++.h>
using namespace std;

int N[10000050];
vector<int> A;

void div(int x){
	int i;
	for(i=1; i*i<=x;i++)
		if(x%i == 0)
			N[x]+=2;
	i--;
	if(i*i == x)
		N[x]--;		
}

int BS(int low, int high, int key){
	int mid;
	while(low <= high){
		mid = low + (high-low)/2;
		if(key < A[mid])
			high = mid - 1;
		if(key > A[mid])
			low = mid + 1;
		if( key == A[mid] )
			break;
	}
	return mid;
}
int main(){

	int T,x = 1,a,b,pos1,pos2;
	div(x);
	A.push_back(1);
	while(x < 1000005){
		x = x + N[x];
		div(x);
		A.push_back(x);	
	}

	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		scanf("%d %d",&a,&b);
		pos1 = BS(0,A.size()-1,a);
		if(A[pos1] < a) pos1++;
		pos2 = BS(0,A.size()-1,b);
		if(A[pos2] > b) pos2--;
		
		printf("Case %d: %d\n",i,(pos2-pos1+1));
	}		
	return 0;
}
