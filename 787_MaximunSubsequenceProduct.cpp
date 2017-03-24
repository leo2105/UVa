#include <bits/stdc++.h>
using namespace std;

int kadane ( vector<int> A ){
	int act_max, prev_max, prev_min, act_min, ans;
	act_min = act_max = prev_max = prev_min = ans = A[0];
	
	for ( int i = 1 ; i < (int)A.size() ; i++){
		act_max = max ( prev_max * A[i] , max ( prev_min * A[i] , A[i] ) );
		act_min = min ( prev_max * A[i] , min ( prev_min * A[i] , A[i] ) );
		ans = max ( ans , act_max );
		prev_max = act_max;
		prev_min = act_min;
	}
	return ans;
}

int main(){
	int a;	
	vector<int> A ;
	while ( cin >> a ){
		if ( a == -999999 ){
			cout << ( kadane ( A ) ) << endl;
			A.clear();
			continue;
		}
			A.push_back(a);
	}

	return 0;
}
