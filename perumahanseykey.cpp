#include <iostream>
#include <list>
#include <vector>
#include <cmath>
using namespace std;

class Graph{
    private:
        int V;
    public:
        vector<int> *adj;
        Graph(int v);
        void addEdge(int v, int w);
        void BFS(int s);
};

Graph::Graph(int V){
    this->V = V;
    adj = new vector<int>[V];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}

void Graph::BFS(int s){
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
    list<int> queue;
    visited[s] = true;
    queue.push_back(s);
    vector<int>::iterator i;
    while(!queue.empty()){
        s = queue.front();
        cout << s << " -> ";
        queue.pop_front();
        for (i = adj[s].begin(); i != adj[s].end(); ++i){
            if (!visited[*i]){
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
    cout << "END"<<endl;
}

int main(){
    int kota,jalan;
    cin >> kota;
    Graph g(kota);
    cin >> jalan;
    for(int i=0;i<jalan;i++){
        int angka1, angka2;
        cin >> angka1 >> angka2;
        g.addEdge(angka1,angka2);
    }
    int BFS;
    cin >> BFS;
    g.BFS(BFS);
    return 0;
}