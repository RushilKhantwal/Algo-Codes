#include<iostream>
#include<unordered_map>
#include<cstring>
#include<list>
using namespace std;

class Graph{
 unordered_map <string,list<pair<string,int>>> L;
    public:
        void addEdge(string x, string y, bool bidir,int value)
            {
                L[x].push_back(make_pair(y,value));
                    if(bidir)
                            L[y].push_back(make_pair(x,value));
            }
          void printAdjList(){
              for(auto p:L)
              {
                  string city = p.first;
                  list<pair<string,int>> nbrs = p.second;
                    cout<< city <<" ->";
                    for(auto nbr:nbrs)
                        {
                            string dest = nbr.first;
                            int dist = nbr.second;

                            cout<<dest<<" "<<dist<<",";
                        }
                            cout<<endl;
              }

          }
};
int main()
{
    Graph g;
    g.addEdge("A","B",true,20);
    g.addEdge("B","D",true,30);
    g.addEdge("A","C",true,10);
    g.addEdge("C","D",true,40);
    g.addEdge("A","D",false,50);
    g.printAdjList();
    return 0;
}
