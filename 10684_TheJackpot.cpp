#include <cstdio>
using namespace std;

int main(){
	int N,a,act,rpta;
	while(1){
		scanf("%d",&N);
		if ( N == 0) break;
		scanf("%d",&a);
		rpta = a;
		act = (a > 0 ? a : 0);
		for ( int i = 1 ; i < N ; ++i ){
			scanf("%d",&a);
			act = ( act > 0 ? act + a : a );
			rpta = ( act > rpta ? act : rpta );
		}
		rpta > 0 ? printf("The maximum winning streak is %d.\n",rpta) : printf("Losing streak.\n");
	}
	return 0;
}
