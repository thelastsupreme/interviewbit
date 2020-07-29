// Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.

#include <bits/stdc++.h>
using namespace std;

struct UndirectedGraphNode
{
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x){};
};

//Recursive Approach
unordered_map<UndirectedGraphNode*,UndirectedGraphNode*> m; //map from node to its clone
UndirectedGraphNode* cloneGraph(UndirectedGraphNode *node) {
    if(!node)return NULL;
    UndirectedGraphNode* root = new UndirectedGraphNode(node->label); //create a new Node with the same label as node
    m[node] = root; //assign 
    for(auto n : node->neighbors) {  //dfs of neighbours
        if(m.find(n)==m.end()) {     //if that neighbour doesnt exsist in map yet
            UndirectedGraphNode* nei = cloneGraph(n); //create it
            root->neighbors.push_back(nei);           //and then push it 
        } else {
            root->neighbors.push_back(m[n]);          //if the node already exists then just push that node from map
        }
    }
    return root;
}


//using BFS
UndirectedGraphNode *cloneGraph_BFS(UndirectedGraphNode *graph)
{
    if (!graph)
        return NULL;

    map<UndirectedGraphNode *, UndirectedGraphNode *> map;
    queue<UndirectedGraphNode *> q;
    q.push(graph);

    UndirectedGraphNode *graphCopy = new UndirectedGraphNode(graph->label);
    map[graph] = graphCopy;

    while (!q.empty())
    {
        UndirectedGraphNode *node = q.front();
        q.pop();
        int n = node->neighbors.size();
        for (int i = 0; i < n; i++)
        {
            UndirectedGraphNode *neighbor = node->neighbors[i];
            // no copy exists
            if (map.find(neighbor) == map.end())
            {
                UndirectedGraphNode *p = new UndirectedGraphNode(neighbor->label);
                map[node]->neighbors.push_back(p);
                map[neighbor] = p;
                q.push(neighbor);
            }
            else
            { // a copy already exists
                map[node]->neighbors.push_back(map[neighbor]);
            }
        }
    }

    return graphCopy;
}
