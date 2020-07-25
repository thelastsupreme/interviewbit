// There are A islands and there are M bridges connecting them. Each bridge has some cost attached to it.

// We need to find bridges with minimal cost such that all islands are connected.

// It is guaranteed that input data will contain at least one possible scenario in which all islands are connected with each other.

// Input Format:

// The first argument contains an integer, A, representing the number of islands.
// The second argument contains an 2-d integer matrix, B, of size M x 3:
//     => Island B[i][0] and B[i][1] are connected using a bridge of cost B[i][2].
// Output Format:

// Return an integer representing the minimal cost required.
// Constraints:

// 1 <= A, M <= 6e4
// 1 <= B[i][0], B[i][1] <= A
// 1 <= B[i][2] <= 1e3
// Examples:

// Input 1:
//     A = 4
//     B = [   [1, 2, 1]
//             [2, 3, 4]
//             [1, 4, 3]
//             [4, 3, 2]
//             [1, 3, 10]  ]

// Output 1:
//     6

// Explanation 1:
//     We can choose bridges (1, 2, 1), (1, 4, 3) and (4, 3, 2), where the total cost incurred will be (1 + 3 + 2) = 6.

// Input 2:
//     A = 4
//     B = [   [1, 2, 1]
//             [2, 3, 2]
//             [3, 4, 4]
//             [1, 4, 3]   ]

// Output 2:
//     6

// Explanation 2:
//     We can choose bridges (1, 2, 1), (2, 3, 2) and (1, 4, 3), where the total cost incurred will be (1 + 2 + 3) = 6.

//solution kruskals min spanning tree
#include <bits/stdc++.h>
using namespace std;

void print(vector<int>A)
{
    for(int i=0;i<A.size();i++)
        cout<<A[i]<<" ";
    cout<<endl;
}

class Graph
{
    int V;                                         //number of vertices
    vector<pair<int,pair<int,int>>>edges;         // weight,from ,to 
public:
    Graph(int V);
    void addEdge(int u,int v,int w);
    int kruskal();
    int findd(vector<int>&parent,int i);
    void unionn(vector<int>&parent,int x,int y);
};


Graph::Graph(int V)   //constructor
{
    this->V=V;
    edges=vector<pair<int,pair<int,int>>>();
    
}
void Graph::addEdge(int u ,int v,int w)
{
   edges.push_back(make_pair(w,make_pair(u,v)));
}

int Graph::findd(vector<int>&parent,int i)  //basically checks if your nodes on dfs traversing end at same nodes
{
    if(parent[i]==-1)
        return i;
    return findd(parent,parent[i]);
}

void Graph::unionn(vector<int>&parent,int x,int y)
{
    int xset=findd(parent,x);
    int yset=findd(parent,y);
    parent[xset]=yset;      //we assign the end point as the next vertex on traversing
}
int Graph::kruskal()
{
    int result=0;
    vector<int>parent(V,-1);
    sort(edges.begin(),edges.end());
    for(int i=0;i<edges.size();i++)
    {
        // print(parent);
        int u=edges[i].second.first;
        int v=edges[i].second.second;
        // cout<<u<<" "<<v<<endl;
        int set_u=findd(parent,u);
        int set_v=findd(parent,v);
        // cout<<set_u<<" "<<set_v<<endl;
        if(set_u!=set_v)  //if they dont end at same nodes it means u can add an edge without making a cycle
        {
            cout<<u<<"-"<<v<<endl;
            result+=edges[i].first;
            unionn(parent,set_u,set_v); //now call the union to assign thier next closest node
        }
    }
    return result;
}
int main()
{
    int V = 9;
    Graph g(V);

    //  making above shown graph
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    cout << "Edges of MST are \n";
    int mst_wt = g.kruskal();

    cout << "\nWeight of MST is " << mst_wt;

    return 0;
}
