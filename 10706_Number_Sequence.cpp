#include <bits/stdc++.h>
using namespace std;

const int oo = INT_MAX;

int BS(int low, int high, int key, vector<long long> A){
	int mid;
	while(low <= high){
		mid = low + (high- low)/2;
		if(A[mid] < key) low = mid + 1;
		if(A[mid] > key) high = mid - 1;
		if(A[mid] == key) break;
	}
	return mid;
}


int count(int x){
	int dig=0,aux=x;
	while(aux != 0){
		dig++;
		aux/=10;
	}
	int rpta = dig * x;
	for(int i=0;i<dig-1;i++){
		rpta -= (pow(10,i+1) - 1);
	}
	return rpta;
}

void f(int y, int cont){
	vector<int> D;
	while(cont != 0){
		D.push_back(cont%10);
		cont /= 10;
	}

	reverse(D.begin(),D.end());
	cout<<(D[y-1])<<endl;
}

int dig(int X){
	int cont = 0;
	while(X != 0){
		X/=10;
		cont++;
	}
	return cont;
}
int main(){

	int bs1,bs2,x,y,z;
	vector<long long> A, B;	

	A.push_back(1);
	for(int i = 2; i <= 50000; ++i)
		A.push_back(A[i-2] + count(i));
	//for(int i=0;i<A.size();i++) cout<<A[i]<<" ";
	//cout<<endl;	
	int T;
	cin>>T;
	
	while(T--){
		B.clear();
		cin>>x;

		if(x == 1){ cout<<1<<endl; continue;}

		bs1 = BS(0, A.size()-1, x, A);
		if(A[bs1] < x) bs1++;
		//cout<<bs1<<endl;		
		y = x - A[bs1-1];		
		//cout<<y<<endl;		
		//int n2 = ceil(sqrt(bs1));
		
		B.push_back(1);
		for(int i = 2; i <= 50000; ++i)
			B.push_back(B[i-2] + dig(i));
		
		//for(int i=0;i<B.size();i++) cout<<B[i]<<" ";
		if(y == 1) {cout<<1<<endl;continue;}
		bs2 = BS(0, B.size()-1, y, B);
		if(B[bs2] < y) bs2++;
		
		//cout<<bs2<<endl;
		z = y - B[bs2-1];
		
		int cont = 1;
		//cout<<"hola"<<endl;
		//cout<<y<<" "<<dig(cont)<<endl;
		//while(y > dig(cont)){
		//	y -= dig(cont);
		//	cont++;	
		//}
		//cout<<"h"<<endl;		
		f(z, bs2+1);
	}
	
	return 0;
}
