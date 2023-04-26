#include<bits/stdc++.h>
using namespace std;

class Graph{
	int v;
	list<int> * adjList;
public:
	Graph(int v){
		this->v=v;
		adjList= new list<int>[v];
	}
	void addEdge(int v,int w){
		adjList[v].push_back(w);
	}

    void shortestPathUnweighted(int s){
        queue<pair<int,int>> qt;
        vector<bool> visited(v,false);

        qt.push(pair<int,int>(s,0));
        visited[s] = true;

        while(!qt.empty()){
            auto curr = qt.front();
            qt.pop();

            s = curr.first;
            
            cout << s << "-->" << curr.second << endl;

            for(auto it = adjList[s].begin(); it != adjList[s].end(); it++){
                if(visited[*it] == false)
                {
                    visited[*it] = true;
                    qt.push(pair<int,int>(*it,curr.second+1));
                }
            }
        }
    }

};

int main(){
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 1);

    g.shortestPathUnweighted(0);
    return 0;
}