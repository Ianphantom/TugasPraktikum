#include <iostream>
#include <list>
#include <queue>
#define INF 0x3f3f3f3f 

using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
typedef pair<ll,ll> myPair;
ll subSize[100010];
ll ans;
ll n,m;

class Graph{
    ll V;
    list<myPair> *adj;
public:
    Graph(ll V);
    void addEdge(ll u,ll v,ll w);
    void dfs(ll u,ll prev);
};
Graph::Graph(ll V){
    this->V = V;
    adj = new list<myPair>[100010];
}
void Graph::addEdge(ll u,ll v,ll w){
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
}
ll tambah(ll x,ll y)
{
    return ((x % MOD) + (y % MOD)) % MOD;
}

ll kali(ll x,ll y)
{
    return ((x % MOD) * (y % MOD)) % MOD;
}

void Graph::dfs(ll u,ll prev){
    subSize[u] = 1;
    for (auto it : adj[u]) if (it.first != prev){
        dfs(it.first,u);
        subSize[u] += subSize[it.first];
        ans = tambah(ans,kali(kali(subSize[it.first],n - subSize[it.first]),it.second));
    }
}
int main(){
    cin >> n >> m; 
    Graph g(n); 
    for(ll i=0;i<m;i++){
        ll node1,node2,jarak;
        cin >> node1 >>node2>>jarak;
        g.addEdge(node1-1,node2-1,jarak);
    }
    g.dfs(1,-1);
    cout << ans << endl;
    return 0; 
}