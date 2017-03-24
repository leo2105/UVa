/*#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <string.h>
 
using namespace std;
 
#define MAX 205
int parent[MAX];
bool doublets(string a, string b) {
    int d=0;
    for (size_t i = 0; i < a.length(); i++)  d+= (a[i]!=b[i]);
    return d==1;
}

int printPath(int ai, int zi, vector<string> ws) {

    int cont = 0;
    while(ai != zi){
        cont++;
        zi = parent[zi];
    }
    //if (ai != zi)
    //    {cont++;
        //printPath(ai, parent[zi], ws);}
    //cout << ws[zi] << endl;
    //if(ai == zi) 
    return cont;
}
int main() {
    int T; cin>>T;
    while(T--){
        string a, z, word;
        
        vector<string> words[MAX];
        while (getline(cin, word) && word[0] != '*') {
            if(words[word.size()].empty()) 
                words[word.size()].push_back(""); // sentiel to start @ i=1.
            words[word.size()].push_back(word);
        }

        //int CASE = 0;
        int aux;
        while (getline(cin, word) && word.size() ) {
            aux = word.find(" ");
            a = word.substr(0,aux);
            z = word.substr(aux+1,(int)word.size()-aux-1);
            //if (CASE++)
            //    cout << endl;

            cout<<a<<" "<<z<<endl;
            //cout<<a.size()<<" "<<z.size()<<endl;
            vector<string> ws = words[a.size()];
            size_t ai = find(ws.begin(), ws.end(), a) - ws.begin();
            size_t zi = find(ws.begin(), ws.end(), z) - ws.begin();
     
            if (a.size() != z.size() || ai == ws.size() || zi == ws.size())
                cout << "-1" << endl;
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
              
                if(!parent[zi]) cout << "-1" << endl;
                else cout<<printPath(ai, zi, ws);
            }
        }
        cout<<endl;
    }
    return 0;
}*/

    #include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
using namespace std;

map<string,int> visited;

int bfs(string start, string to, map< string,vector<string> > graph){
  
  queue<string> s;
  s.push(start);
  visited[start]=0;
  while(s.empty()==false){
    string top = s.front();
    s.pop();
    if(top==to)
      return visited[top];
    int total =graph[top].size();
    for (int i = 0; i < total; ++i)
    {
      if(!visited.count(graph[top][i])){
        visited[graph[top][i]]=visited[top]+1;
        s.push(graph[top][i]);
      }
    }
  }
}

int main(){
  int n;scanf("%d",&n);
  while(n--){
    map<string, vector<string> > graph;
    string word,tmp;
    cin>>word;
    while(word != "*"){
      graph[word];
      map<string, vector<string> >::const_iterator it;
      for (it = graph.begin(); it != graph.end(); ++it)
      {
        tmp=(*it).first;
        int tamTmp = tmp.size(),dif=0;
        if(tamTmp == word.size()){
          for (int i = 0; i < tamTmp && dif<2; ++i)
          {
            if(tmp[i]!=word[i])
              dif++;
          }
          if(dif==1){
            graph[tmp].push_back(word);
            graph[word].push_back(tmp);
          }
        }
      }
      cin>>word;
    }
    string start,to,line;
    size_t pos;
    getline(cin,line);
    getline(cin,line);
    while(line != ""){
      pos = line.find(" ");
      start = line.substr(0,pos);
      to = line.substr(pos+1,line.size());
      visited.clear();
      cout<<start<<" "<<to<<" "<<bfs(start,to,graph)<<endl;
      if(!getline(cin,line))
        break;
    }
    if(n != 0)
      cout<<endl;
  }
  return 0;
}
