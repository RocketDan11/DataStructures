
/* Graph read from file, and represnted as adjacency list. 
 * Each entry in the file is an edge represented as <source vertex, destination 
vertex, edge weight>
To implement DFS and BFS traversals on the graph. 
Note that there is more than one right order of BFS and DFS vertices
*/
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <set>
#include <queue>
using namespace std;

// Each vertex has an integer id. 
typedef vector<vector<pair<int,int>>> adjlist; // Pair: (head vertex, edge weight)
adjlist makeGraph(ifstream& ifs);
void printGraph(const adjlist& alist);
vector<int> BFS(const adjlist& alist, int source); // Return vertices in BFS order
vector<int> DFS(const adjlist& alist, int source);  // Return vertices in DFS order
void DFSHelper(const adjlist& alist, vector<int>& dfslist, vector<bool>& visited, int source);
void printQ(queue<int> qcopy);


    // DFS - returns list of nodes in DFS order starting from source vertex
    vector<int> DFS(const adjlist& alist, int source) {
            vector<int> dfslist;
            vector<bool> visited(alist.size(), false);
            DFSHelper(alist, dfslist, visited, source);
            return dfslist;
    }

void DFSHelper(const adjlist& alist, vector<int>& dfslist, vector<bool>& visited, int source) {
    visited[source] = true;
    dfslist.push_back(source);
    for (auto adjacent : alist[source]){
        if(!visited[adjacent.first]){
            DFSHelper(alist, dfslist, visited, adjacent.first);
        }
    }
}

    // BFS - returns list of nodes in BFS order starting from source vertex
    vector<int> BFS(const adjlist& alist, int source) {
    vector<bool> visited(alist.size(), false);
    vector<int> bfslist;
    queue<int> q;

    //add to queue and mark as visited.
    q.push(source);
    visited[source] = true;

    while(!q.empty()){
        int current = q.front();
        bfslist.push_back(current);
        q.pop();

        for (auto adjacent: alist[current]){
            //check if not visited yet.
            if(!visited[adjacent.first]){
                visited[adjacent.first] = true;
                q.push(adjacent.first);
            }
        }
    }
    return bfslist;
    }

// Reads a csv graph from file and returns an adjacency list
adjlist makeGraph(ifstream& ifs) {
    int vh, vt, wt;
    string line;
    unordered_multimap<int, pair<int, int>> elist;
    set<int> vlist;
    
    while (getline(ifs, line)) {
        stringstream ss(line);
        ss >> vt;
        if (ss.peek() == ',')
            ss.ignore();
        ss >> vh;
        if (ss.peek() == ',')
            ss.ignore();
        ss >> wt;
        elist.emplace(vt, make_pair(vh, wt));   
        vlist.insert(vt);
        vlist.insert(vh);
    }
    
    adjlist res(vlist.size()); // Preallocate vector
    
    for (auto& ele : elist) {
        res.at(ele.first).push_back(make_pair(ele.second.first, 
ele.second.second));
    }
    return res;
}
// Prints the adjacency list (only vertices, not edge weights)
void printGraph(const adjlist& alist) {
    int i = 0;
    for (auto& v : alist) {
        cout << i++ << ": ";
        for (auto& av : v) {
            cout << av.first << " ";
        }
        cout << endl;
    }
}
// Prints queue for debugging
void printQ(queue<int> qcopy) {
    while (!qcopy.empty()) {
        cout << qcopy.front();
        qcopy.pop();
    }
    cout << endl;
}


int main() {
    ifstream ifs("sample_edges.txt");
    adjlist alist = makeGraph(ifs);
    printGraph(alist);
    vector<int> dfslist = DFS(alist, 0);
    for (auto& ele : dfslist) // Prints 0 2 4 5 1 3. Other answers possible 
        cout << ele << " ";
    cout << endl;
    
    vector<int> bfslist = BFS(alist, 0);
    for (auto& ele : bfslist) // Prints 0 2 1 4 3 5. Other answers possible 
        cout << ele << " ";
    cout << endl;
}