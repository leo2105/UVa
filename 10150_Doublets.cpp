/*#include <bits/stdc++.h>
#define N 26000
using namespace std;

vector<int> Graph[N];
vector<string> A;
vector<string> B;
int ant[N];
int d[N];
bool vis[N];

void BFS(int source){
    queue<int> Q;
    d[source] = 0;
    vis[source] = true;
    Q.push(source);
    
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        //FOR(it,Graph[u]){
        for(int i=0;i<Graph[u].size();i++){
            int v=Graph[u][i];
            if(!vis[v]){
                vis[v]=true;
                ant[v] = u;
                d[v] = d[u]+1;
                Q.push(v);
            }
        }
    }
}

int main(){
	string s;
	string s1,s2;
    int cont1,cont2,cont,aux;
	while(getline(cin,s)){
        if(s.size() == 1)
            break;
        A.push_back(s.substr(0,s.size()-1));
	}

    for (int i = 0; i < N; ++i)
    {
        ant[i] = -1;
    }

    for ( int i = 0 ; i < A.size() ; i++ )
            for ( int j=0 ; j < A.size() ; j++ )
            {
                cont = 0;
                if ( A[i].size() == A[j].size()){
                    
                    for(int a = 0; a < A[i].size() ; a++)
                        if(A[i][a] != A[j][a])
                            cont++;
                }

                if(cont == 1)
                    Graph[i].push_back(j);

            }
    bool flag = false;
    while(cin>>s1>>s2){
        if(flag){
            cout<<endl;}
        for(int i=0;i<A.size();i++){
            if(s1 == A[i])
                {cont1 = i;}
            if(s2 == A[i])
                {cont2 = i;}
        }

        BFS(cont1);

        if (d[cont2] == 0)
        {
            if(cont1 == cont2)
                cout<<A[cont1]<<endl;
            else
                cout<<"No solution."<<endl;
        }else{
            aux = cont2;
            while(aux != cont1){
                B.push_back(A[aux]);
                aux = ant[aux];
            }
           
            B.push_back(A[aux]);
            for( int i = (int)B.size()-1 ; i >= 0 ; i-- )
                cout<<B[i]<<endl;
        }
        flag = true;
        
    }

	return 0;
}*/

#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <string.h>
 
using namespace std;
 
#define MAX 26000
int parent[MAX];
bool doublets(string a, string b) {
    int d=0;
    for (size_t i = 0; i < a.length(); i++)  d+= (a[i]!=b[i]);
    return d==1;
}
void printPath(int ai, int zi, vector<string> ws) {
    if (ai != zi)
        printPath(ai, parent[zi], ws);
    cout << ws[zi] << endl;
}
int main() {
 
    string a, z, word;
    
    vector<string> words[MAX];
    while (getline(cin, word) && word.size()) {
        if(words[word.size()].empty()) words[word.size()].push_back(""); // sentiel to start @ i=1.
        words[word.size()].push_back(word);
    }

    int CASE = 0;
    while ((cin >> a >> z)) {
        if (CASE++)
            cout << endl;
        vector<string> ws = words[a.size()];
        size_t ai = find(ws.begin(), ws.end(), a) - ws.begin();
        size_t zi = find(ws.begin(), ws.end(), z) - ws.begin();
 
        if (a.size() != z.size() || ai == ws.size() || zi == ws.size())
            cout << "No solution." << endl;
        else {
            memset(parent, 0, sizeof parent);
            parent[ai] = ai;
            queue<size_t> q;
            q.push(ai);
            while (q.size() && q.front() != zi) {
                int u = q.front();
                q.pop();
                for (size_t v = 0; v < ws.size(); v++) {
                    if (!parent[v] && doublets(ws[u], ws[v])) {
                        parent[v] = u;
                        q.push(v);
                    }
                }
            }
            if(!parent[zi]) cout << "No solution." << endl;
            else printPath(ai, zi, ws);
        }
    }
    return 0;
}