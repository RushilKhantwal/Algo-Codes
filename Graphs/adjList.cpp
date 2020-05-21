#include<iostream>
#include<list>

using namespace std;

class Graph {
    int V;
    list <int> *L;
public:
        Graph(int V)
            {
                this->V = V;
                L = new list<int> [V];

            }
       void addEdge(int x,int y)
                {
                    L[x].push_back(y);
                    L[y].push_back(x);
                }
       void printAdjList()
                    {
                        for(int i=0;i<V;i++)
                        {
                            cout<<"Vertex "<<i<<"->";
                                for(int nbr:L[i])
                                {
                                    cout<<nbr<<",";
                                }
                              cout<<endl;
                        }
                    }
};
int main()
{
    Graph G(4);
    G.addEdge(0,1);
    G.addEdge(0,2);
    G.addEdge(1,2);
    G.addEdge(2,3);
    G.printAdjList();
    return 0;

}
