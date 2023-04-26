#include <bits/stdc++.h>

using namespace std;

template<typename U, typename V>
class Iterator{
    U* cont_data;
    typename vector<V>::iterator it;
    
public:
    
    Iterator(U* cont):cont_data(cont){
        it = cont_data->cont_vec.begin();
    }
    
    void first(){
        it = cont_data->cont_vec.begin();
    }
    
    bool isEnd(){
        return (it == cont_data->cont_vec.end());
    }
    
    void next(){
        it++;
    }
    
    typename vector<V>::iterator curr(){
        return it;
    }
    
};

template<typename V>
class Container{
    vector<V> cont_vec;
    friend class Iterator<Container,V>;
public:
    
    void push(V v){
        cont_vec.push_back(v);
    }
    
    Iterator<Container,V>* getIterator(){
        return new Iterator<Container,V>(this);
    }
    
};

int main()
{
    Container<int> vec;
    vec.push(10);
    vec.push(20);
    vec.push(30);
    vec.push(40);
    
    Iterator<Container<int>,int> *iter = vec.getIterator();
    
    for(iter->first();!iter->isEnd();iter->next())
    {
        cout << *(iter->curr()) << " ";
    }
    cout << endl;
    
    // similar iterator can be implement for custom class.
    
    return 0;
}