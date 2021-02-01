#include <iostream>
#include <list>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
priority_queue<int> jumlah;

class Graph{
    private:
        int V;
        void DFSUtil(int v, bool visited[]);
    public:
        vector<int> *adj;
        Graph(int v);
        void addEdge(int v, int w);
        int banyakhubungan();
        void printGraph(int V); 
};

Graph::Graph(int V){
    this->V = V;
    adj = new vector<int>[V];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
    adj[w].push_back(v);
}
int node;
int Graph::banyakhubungan()
{
    bool* visited = new bool[V];

    int count = 0;
    for (int v = 0; v < V; v++)
        visited[v] = false;
 
    for (int v = 0; v < V; v++) {
        node = 1;
        if (visited[v] == false) {
            DFSUtil(v, visited);
            count += 1;
            jumlah.push(node);
        }
    }
 
    return count;
}

void Graph::DFSUtil(int v, bool visited[])
{
 
    visited[v] = true;
    vector<int>::iterator i;
 
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i]){
            node++;
            DFSUtil(*i, visited);
        }
            
}
  
void showpq(priority_queue<int> gq,int j)
{
    int kali = 1;
    int hasil = 0;
    while (!jumlah.empty()) {
        hasil = hasil + (kali*jumlah.top());
        jumlah.pop();
        kali++;
    }
    cout <<"Kasus #"<<j+1<<": "<< hasil<<'\n';
}

int main(){
    int kota,jalan,kasus;
    cin >> kasus;
    for(int j=0;j<kasus;j++){
        cin >> kota;
        Graph g(kota);
        cin >> jalan;
        for(int i=0;i<jalan;i++){
            int angka1, angka2;
            cin >> angka1 >> angka2;
            g.addEdge(angka1-1,angka2-1);
        }
        int banyak =  g.banyakhubungan();
        showpq(jumlah,j);
    }
    return 0;
}