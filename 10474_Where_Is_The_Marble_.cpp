#include <bits/stdc++.h>
using namespace std;

vector<int> A;
int pos[1000005];

int BS(int low, int high, int key){
	int mid;
	while(low <= high){
		mid = low + (high-low)/2;
		if(key < A[mid]) high = mid - 1;
		if(key > A[mid]) low = mid + 1;
		if(key == A[mid]) return mid;
	}
	return -1;
}

int main(){
	int N,Q,a,cont = 1,rpta;
	while(true){
		A.clear();
		cin>>N>>Q;
		if(!N && !Q) break;
		A.resize(N);
		memset(pos,0,sizeof((N+5)*4));
		for(int i=0;i<N;i++){
			cin>>A[i];
		}
		sort(A.begin(),A.end());
		pos[0] = 0;
		for(int i=1;i<N;i++){
			if(A[i] == A[pos[i-1]])
				pos[i] = pos[i-1];
			else
				pos[i] = i;
		}
		cout<<"CASE# "<<(cont++)<<":"<<endl;
		//for(int i=0;i<N;i++) cout<<A[i]<<" ";cout<<endl;
		//for(int i=0;i<N;i++) cout<<pos[i]<<" ";cout<<endl;
		for(int i=0;i<Q;i++){
			cin>>a;
			rpta = BS(0,N-1,a);
			rpta == -1 ? cout << a << " not found" : cout << a << " found at "<< (pos[rpta]+1);
			cout<<endl;
		}
		
	}	
	return 0;
}
