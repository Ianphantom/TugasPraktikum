#include<bits/stdc++.h> 
using namespace std; 

typedef pair<long long, long long> iPair; 

struct Graph 
{ 
    long long V, E; 
    vector< pair<long long, iPair> > edges; 

    Graph(long long V, long long E) 
    { 
        this->V = V; 
        this->E = E; 
    } 

    void addEdge(long long u, long long v, long long w) 
    { 
        edges.push_back({w, {u, v}}); 
    } 

    long long findpath(); 
}; 
struct DisjointSets 
{ 
    long long *parent, *rnk; 
    long long n; 
    DisjointSets(long long n) { 
        this->n = n; 
        parent = new long long[n+1]; 
        rnk = new long long[n+1]; 
        for (long long i = 0; i <= n; i++) 
        { 
            rnk[i] = 0; 
            parent[i] = i; 
        } 
    } 
    long long find(long long u) { 

        if (u != parent[u]) 
            parent[u] = find(parent[u]); 
        return parent[u]; 
    } 

    void merge(long long x, long long y) 
    { 
        x = find(x), y = find(y); 
        if (rnk[x] > rnk[y]) 
            parent[y] = x; 
        else 
            parent[x] = y; 

        if (rnk[x] == rnk[y]) 
            rnk[y]++; 
    } 
}; 


long long Graph::findpath(){ 
    long long terpendek = 0;
    sort(edges.begin(), edges.end()); 
    DisjointSets ds(V); 

    vector< pair<long long, iPair> >::iterator it; 
    for (it=edges.begin(); it!=edges.end(); it++){ 
        long long u = it->second.first; 
        long long v = it->second.second; 
        long long set_u = ds.find(u); 
        long long set_v = ds.find(v); 
        if (set_u != set_v) { 
            terpendek += it->first;  
            ds.merge(set_u, set_v); 
        } 
    } 
    return terpendek; 
} 
int main(){ 
    long long V = 7, E = 8; 
    cin >> V >> E;
    Graph g(V, E);
    long long sum=0; 
    for(long long i=0;i<E;i++){
        long long a,b,c;
        cin >> a >> b >> c;
        g.addEdge(a, b, c);
        sum+=c; 
    }
    long long terpendek = g.findpath(); 
    cout << sum - terpendek<<endl; 
    return 0; 
} 