#include<bits/stdc++.h> 
using namespace std; 
# define INF 0x3f3f3f3f

pair<int,int> menor = make_pair(-1, INF);
map<int,int> p;
list<int> Qzin;

class Grafo 
{ 
    int V;    

    list< pair<int, int> > *adj; 
  
public: 
    Grafo(int V);
  

    void AdicionaAdjacencia(int u, int v, int w); 
  
    void Dijkstra(int s); 
}; 
  
Grafo::Grafo(int V) 
{ 
    this->V = V; 
    adj = new list<pair<int,int>> [V]; 
} 
  
void Grafo::AdicionaAdjacencia(int u, int v, int w) 
{ 
    adj[u].push_back(make_pair(v, w)); 
    adj[v].push_back(make_pair(u, w)); 
} 
  

void Grafo::Dijkstra(int origem) 
{ 
    priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq; 

    vector<int> dist(V, INF); 

    pq.push(make_pair(0, origem)); 
    dist[origem] = 0; 
  

    while (!pq.empty()) 
    {
        int u = pq.top().second; 
        pq.pop(); 
  
        list< pair<int, int> >::iterator i; 
        for (i = adj[u].begin(); i != adj[u].end(); ++i) 
        {
            int v = (*i).first; 
            int peso = (*i).second; 
  
            if (dist[v] > dist[u] + peso) 
            {
                dist[v] = dist[u] + peso; 
                pq.push(make_pair(dist[v], v)); 
            } 
        } 
    } 

    for(auto i:Qzin){
        p[dist[i]] = i;
    }
    // for (int i = 0; i < V; ++i) 
    //     printf("%d \t\t %d\n", i, dist[i]); 
}

int main() 
{
    int N,L,Q,aux,x,y;
    Grafo g(10000);
    int menor_value = INF;
    int menor_key = -1;
    cin >> N >> L >> Q;
    
    
    for(int i = 0; i<Q;i++){
        cin >> aux;
        Qzin.push_back(aux-1);
    }

    for(int i = 0; i<L; i++){
        cin >> x >> y;
        g.AdicionaAdjacencia(x-1,y-1,1);
    }

    // g.AdicionaAdjacencia(1,2,1);
    // g.AdicionaAdjacencia(1,7,1);
    // g.AdicionaAdjacencia(2,3,1);
    // g.AdicionaAdjacencia(2,8,1);
    // g.AdicionaAdjacencia(3,4,1);
    // g.AdicionaAdjacencia(4,7,1);
    // g.AdicionaAdjacencia(4,8,1);
    // g.AdicionaAdjacencia(8,5,1);
    // g.AdicionaAdjacencia(5,6,1);
    // g.AdicionaAdjacencia(6,7,1);

    g.Dijkstra(1);

    for(auto x:Qzin){
        // cout << x << " " << p[x] << "\n";
        if(p[x] < menor_value && p[x] != 0){
            menor_key = x;
        }
    }
    cout << menor_key+1 << "\n";

    return 0; 
}

/*
8 10 3
4 7 8
1 2
1 7
2 3
2 8
3 4
4 7
4 8
8 5
5 6
6 7

*/