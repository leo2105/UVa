// std=c++11

#include <bits/stdc++.h>
using namespace std;

// El maximo menor que k
int binarySearch(vector<int> &v, int l, int r, int k){
	int m;
	while(r-l > 1){
		m = l + (l-r)/2;
		if(v[m] >= k)
			r = m;
		else
			l = m;
	}
	return r;
}

int LIS(vector<int> v){
	
	if(v.size() == 0)
		return 0;

	vector<int> tail(v.size(), 0);
	int length = 1;

	tail[0] = v[0];
	for( int i = 1 ; i < v.size(); i++ ){
		if(v[i] < tail[0])
			tail[0] = v[i];
		else
			if (v[i] > tail[length-1])		
				tail[length++] = v[i];
			else
				tail[ binarySearch( tail, -1, length-1, v[i] ) ] = v[i];
	}
	return length;
}
int main(){

	std::vector<int> v{2,5,3,7,11,8,10,13,6};
	cout<<LIS(v)<<endl;
	return 0;
}