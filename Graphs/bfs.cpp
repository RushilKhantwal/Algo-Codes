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
            void bfs(T src)
            {
                map<T,bool> visited;
                queue <T> q;

                q.push(src);
                visited[src]= true;
                while( !q.empty())
                {
                        T node = q.front();
                            q.pop();
                            cout<< node <<" ";

                            for(int nbr:L[node])
                            {
                                if(!visited[nbr]){
                                    q.push(nbr);
                                    visited[nbr] = true;
                                }
                            }
                }
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

    G.bfs(0);
    return 0;
}
