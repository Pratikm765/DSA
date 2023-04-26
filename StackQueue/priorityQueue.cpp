#include<bits/stdc++.h>
using namespace std;

class Edge{
public:
    int x;
    int y;
    int w;
    
    Edge(){
        x = 0; 
        y = 0;
        w = 0;
    }

    Edge(int X,int Y,int W){
        x = X;
        y = Y;
        w = W;
    }
    
    bool operator()(const Edge* lhs, const Edge* rhs) const
    {
        return lhs->w > rhs->w;
    }
};

struct CmpEdgePtrs
{
    bool operator()(const Edge* lhs, const Edge* rhs) const
    {
        return lhs->w > rhs->w;
    }
};

bool operator<(const Edge& e1,const Edge& e2){
    return e1.w > e2.w;
}

bool compare(const Edge& lhs, const Edge& rhs)
{
    return lhs.w > rhs.w;
}


void test(){
    priority_queue<Edge*,vector<Edge*>, Edge> qt;
    // priority_queue<Edge*,vector<Edge*>, CmpEdgePtrs> qt;
    qt.push(new Edge(0,1,4));
    qt.push(new Edge(0,1,8));
    qt.push(new Edge(0,1,2));
    
    cout << qt.top()->w << endl;
    
    priority_queue<Edge> qt2;
    
    qt2.push(Edge(0,1,10));
    qt2.push(Edge(0,1,3));
    
    cout << qt2.top().w << endl;
    
    priority_queue<Edge, vector<Edge>, function<bool(Edge, Edge)>> qt3(compare);
    
    qt3.push(Edge(0,1,10));
    qt3.push(Edge(0,1,3));
    
    cout << qt3.top().w << endl;
    
    auto compare2 = [](Edge a, Edge b) { return a.w < b.w; };
    
    priority_queue<Edge, vector<Edge>, decltype(compare2)> qt4(compare2);
    
    qt4.push(Edge(0,1,10));
    qt4.push(Edge(0,1,3));
    
    cout << qt4.top().w << endl;

}

int main(){
    test(); 
    return 0;
}