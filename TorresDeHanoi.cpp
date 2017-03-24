#include <bits/stdc++.h>
#define f(i,x,y) for(int i=x;i<y;i++)
#define vi vector<int>
using namespace std;

vi A;
int T,N;
bool perfectSquare(int n)
{
	int aux=sqrt(n);
	if(aux*aux == n)
		return true;
	return false;
}

void imprimir(vi A)
{
	f(i,0,N)
		cout<<A[i]<<" ";
	cout<<endl;
}
int main()
{

	
	cin>>T;
	while(T--)
	{
		
		cin>>N;
		A.resize(N);
		f(i,0,N)
			A[i]=0;
		bool flag=false;
		int j=1;
		while(!flag)
		{
			//cout<<"hola";
			int band=0;
			for(int i=0;i<N && band==0;i++)
			{
				if(perfectSquare(A[i]+(j)) && A[i]!=0)
				{
					A[i]=j;band=1;
				}
				if(A[i]==0 && band==0)
				{
					A[i]=j;band=1;
				}
			}

			int out=0;
			for(int i=0;i<N && out==0;i++)
			{
				if(A[i]==j)
					out=1;
			}
			if(out==0)
				flag=true;

			
			j++;
			//cout<<j;
			imprimir(A);

		}
		cout<<j-2<<endl;
	}
	return 0;
}