    #include <bits/stdc++.h>
    using namespace std;
     

    typedef long long ll;
    typedef vector<int> vi;
    typedef pair<int, int> ii;
    typedef vector<ii> vii;
    typedef set<int> si;
    typedef map<string, int> msi;
     
    #define REP(i, a, b) for(int i=int(a); i < int(b); i++)
    #define TRvi(c, it) for(vi::iterator it = (c).begin(); it != (c).end(); it++)
    #define TRvii(c, it) for(vii::iterator it = (c).begin(); it != (c).end(); it++)
    #define TRmsi(c, it) for(msi::iterator it = (c).begin(); it != (c).end(); it++)
    #define INF 2000000000
    #define pb push_back
    #define N 100
     
    vi Graph[N];
    int d[N];
    int vis[N];
    int rpta;
     
    void BFS(int source){
            queue<int> Q;
            d[source] = 0;
            vis[source] = 1;
            Q.push(source);
            printf("Se agrego: %d\n",source);
            while(!Q.empty()){
                    int u = Q.front();
                    Q.pop();
                    TRvi(Graph[u], it){
                            int v=*it;
                            if(!vis[v]){
                                    vis[v]=1;
                                    d[v] = d[u]+1;
                                    Q.push(v);
                            }
                    }
            }

    }
     
     
    int main(){
    		int q;
    		int source,TTL;
            map <int,int> mi_mapa,mi_mapa_rev;
            int u,v;
            int id=1;
            for(int i=0;i<16;i++)
            {

            }
            for(int i=0;i<16;i++)
            {
                cin>>u>>v;
                if(mi_mapa.find(u) == mi_mapa.end() && mi_mapa[] )
                {
            
                    mi_mapa[id]=u;
                    id++;

                }
                if(mi_mapa.find(v) == mi_mapa.end() )
                {
                    mi_mapa[id]=v;
                    id++;
                }     
            }

            for(int i=1;i<=16;i++)
            {
                cout<<"mimapa["<<i<<"] = "<<mi_mapa[i]<<endl;
            }
    		/*while(cin>>q)
    		{
            	memset(d, -1, sizeof d);
            	memset(vis, 0, sizeof vis);
           		int m,n;
           		for(int i=0;i<q;i++)
           		{	
           			cin>>m>>n;
           			Graph[m].pb(n);
           			Graph[n].pb(m);
            	}
            	cin>>source;
            	cin>>TTL;
            	while(cin>>source || since>>TTL)
            	{
            		rpta=0;
            		BFS(source);
            		REP(i, 1, )
            			if(d[i]>TTL)
            				rpta++;
            		cout<<endl<<rpta<<endl;
            		cin>>source;
            		cin>>TTL;
            	}
            }
            */
            /*
            memset(d, -1, sizeof d);
            memset(vis, 0, sizeof vis);
            Graph[1].pb(2);
            Graph[1].pb(3);
            Graph[2].pb(6);
            Graph[3].pb(4);
            Graph[3].pb(5);
            Graph[6].pb(9);
            Graph[4].pb(7);
            Graph[5].pb(8);
            Graph[9].pb(10);
            Graph[3].pb(10);

            Graph[2].pb(1);
            Graph[3].pb(1);
            Graph[6].pb(2);
            Graph[4].pb(3);
            Graph[5].pb(3);
            Graph[9].pb(6);
            Graph[7].pb(4);
            Graph[8].pb(5);
            Graph[10].pb(9);
            Graph[10].pb(3);
            
            BFS(6);      
            REP(i, 1, 11) cout<<"D["<<i<<"]="<<d[i]<<endl;
            cout<<"Ingresar el TTL";
            cin>>TTL;
            REP(i, 1, 11)
            	if(d[i]!=TTL)
            		rpta++;
            cout<<rpta;*/
            return 0;
    }
/*
    #include <bits/stdc++.h>
    using namespace std;
     

    typedef long long ll;
    typedef vector<int> vi;
    typedef pair<int, int> ii;
    typedef vector<ii> vii;
    typedef set<int> si;
    typedef map<string, int> msi;
     
    #define REP(i, a, b) for(int i=int(a); i < int(b); i++)
    #define TRvi(c, it) for(vi::iterator it = (c).begin(); it != (c).end(); it++)
    #define TRvii(c, it) for(vii::iterator it = (c).begin(); it != (c).end(); it++)
    #define TRmsi(c, it) for(msi::iterator it = (c).begin(); it != (c).end(); it++)
    #define INF 2000000000
    #define pb push_back
    #define N 100
     
    vi Graph[N];
    int d[N];
    int vis[N];
     
    void BFS(int source){
            queue<int> Q;
            d[source] = 0;
            vis[source] = 1;
            Q.push(source);
            printf("Se agrego: %d\n",source);
            while(!Q.empty()){
                    int u = Q.front();
                    Q.pop();
                    TRvi(Graph[u], it){
                            int v=*it;
                            if(!vis[v]){
                                    vis[v]=1;
                                    d[v] = d[u]+1;
                                    Q.push(v);
                            }
                    }
            }
    }
     
     
    int main(){
    		int q;
    		int source,TTL;
    		while(cin>>q)
    		{
            	memset(d, -1, sizeof d);
            	memset(vis, 0, sizeof vis);
           		int m,n;
           		for(int i=0;i<q;i++)
           		{	
           			cin>>m>>n;
           			Graph[m].pb(n);
           			Graph[n].pb(m);
            	}
            	cin>>source>>TTL;
            	while(source!=0 && TTL!=0)
            	{
            		BFS(source)
            	}

            }*/
            /*
            Graph[1].pb(2);
            Graph[1].pb(3);
            Graph[2].pb(6);
            Graph[3].pb(4);
            Graph[3].pb(5);
            Graph[6].pb(9);
            Graph[4].pb(7);
            Graph[5].pb(8);
            Graph[9].pb(10);
            Graph[3].pb(10);

            Graph[2].pb(1);
            Graph[3].pb(1);
            Graph[6].pb(2);
            Graph[4].pb(3);
            Graph[5].pb(3);
            Graph[9].pb(6);
            Graph[7].pb(4);
            Graph[8].pb(5);
            Graph[10].pb(9);
            Graph[10].pb(3);
            *//*
            BFS(6);      
            REP(i, 1, 11) cout<<"D["<<i<<"]="<<d[i]<<endl;
            
            return 0;
    }

*/