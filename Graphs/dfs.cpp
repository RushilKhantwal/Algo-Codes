
#include<iostream>
#include<map>
#include<list>
#include<queue>
using namespace std;

template <typename T>
class Graph{

        map<T,list<T>> L;
    public:
            void addEdge(int x,int y)
                {
                    L[x].push_back(y);
                    L[y].push_back(x);
                }
                void dfs_helper(T src, map<T,bool> &visited)
                {
                    cout<<src<<" ";
                    visited[src]=true;
                    for(T nbr:L[src])
                    {
                        if(!visited[nbr])
                        {
                            dfs_helper(nbr,visited);
                        }
                    }
                }
            void dfs(T src)
            {
                map<T,bool> visited;
                for(auto p:L)
                {
                    T node = p.first;
                    visited[node]=false;
                }
               dfs_helper(src,visited);
            }
};

int main()
{
    Graph <int>G;
    G.addEdge(0,1);
    G.addEdge(1,2);
    G.addEdge(2,3);
    G.addEdge(3,4);
    G.addEdge(4,5);

    G.dfs(0);
    return 0;
}
