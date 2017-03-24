#include <bits/stdc++.h>
#define F(i,a,b) for(int i=a;i<b;i++)
using namespace std;
/*
const int oo = (1<<30)+(1<<29);
const int N = 20;
int n, r, k;

int dp[2i*N+5][2*N+5][2][N+5][2];

int f ( int x, int cont, int ant, int altura, int pos ) {

	
	if ( altura < 0 || altura > n || x > 2*n || cont > r ) return 0;
	int aux = cont;;
	if ( ant == -1 && pos == -1 && altura == k) aux = cont + 1;
	if ( x == 2*n) return (altura == 0 && cont == r ? 1 : 0);
	

	if ( dp[x][cont][ant][altura][pos] != oo) return dp[x][cont][ant][altura][pos];		
	
	return (dp[x][cont][ant][altura][pos] = f( x+1, aux, pos*-1, altura + pos, -1 ) + f ( x+1, aux, pos*-1, altura + pos , 1 ));

}
int main(){
	cin >> n >> r >> k;
	F(a,0,2*N+5) F(b,0,2*N+5) F(c,0,2) F(d,0,N+5) F(e,0,2) dp[a][b][c][d][e] = oo;
	cout << f ( 0, 0, -1, 0, 1)/2 << endl;
	//cout << dp[2*N][r][1][0][1] << endl;
	//cout << f( 1, 0, -1, 1, 1 ) + f( 1, 0, -1, 1, -1 )  << endl;		
	return 0;
}*/


const int MAX_Y = 20;
const int MAX_X = 40;
const int MAX_NUM_PEAK = 20;
const int MAX_TARGET_HEIGHT = 20;
const int NUM_DIRECTION = 2;
const int UP = 0;
const int DOWN = 1;

int countNumPath(int x, int y, int numPeak, int prevDirection, int targetHeight, int maxX, int maxY,
                 int memo[MAX_X][MAX_Y][MAX_NUM_PEAK][NUM_DIRECTION])
{
    /*printf("State = (%d, %d, %d, %d, %d)\n", row, col, numPeak, prevDirection, targetHeight);*/
    if(y < 0 || y > maxY)
        return 0;
    if(numPeak < 0)
        return 0;
    if(x == maxX)
    {
        /* The largest x */
        if(y != 0 || numPeak > 0)
            return 0;
        return 1;
    }

    if(memo[x][y][numPeak][prevDirection] >= 0)
        return memo[x][y][numPeak][prevDirection];

    int numPath = 0;
    /* Try to go up */
    numPath += countNumPath(x + 1, y + 1, numPeak, UP, targetHeight, maxX, maxY, memo);
    /* Try to go down */
    int numPeakLeft = numPeak;
    if(prevDirection == UP && y == targetHeight)
        numPeakLeft--;
    numPath += countNumPath(x + 1, y - 1, numPeakLeft, DOWN, targetHeight, maxX, maxY, memo);

    memo[x][y][numPeak][prevDirection] = numPath;
    return numPath;
}
int main(void)
{
    int memo[MAX_X][MAX_Y][MAX_NUM_PEAK][NUM_DIRECTION], n, numPeak, targetHeight;

    while(scanf("%d %d %d", &n, &numPeak, &targetHeight) > 0)
    {
        memset(memo, -1, MAX_X * MAX_Y * MAX_NUM_PEAK * NUM_DIRECTION * sizeof(int));

        printf("%d\n", countNumPath(0, 0, numPeak, UP, targetHeight, 2 * n, n, memo));
    }
    return 0;
}	
