# include <iostream>
using namespace std;
#include <list>
#include <queue>
#include <stack>
class Graph{

public:
    int vertices; //kitny vertices hungyyy (size)
    int * vertexVal; //vertex ki value kya hugi (it will give me value i=on the index (vertix value))
    list<int> *adjencyList; //(it will give me index)

    Graph(int vertices){
        this->vertices =  vertices;
        adjencyList = new list<int>[vertices];
        vertexVal = new int[vertices];
    }

    void addVertex(int index , int value){
        if (index >= vertices ){
            cout << "invalid index your graph has " << vertices <<" indexes";
            return;
        }

        vertexVal[index] = value;

    }
    int degree(int value){

    int index = getIndex(value);

    if(index == -1){
        cout << "Invalid vertex" << endl;
        return -1;
    }

    return adjencyList[index].size();
    }

    int getIndex(int value) {
    for(int i = 0; i < vertices; i++) {
        if(vertexVal[i] == value)
        {
            cout<<"---";
            return i;
        }
    }
    return -1; // not found
    }


    void addEdge(int v1, int v2) {
        //for undirected
    
    int i1 = getIndex(v1);
    int i2 = getIndex(v2);

    if(i1 == -1 || i2 == -1) {
        cout << "Invalid vertex value!" << endl;
        return;
    }

    adjencyList[i1].push_back(i2);
    adjencyList[i2].push_back(i1);
    }

    

    void printAdjencyList(){
        for (int i = 0; i < vertices ; i++){
            cout << vertexVal[i] << " : " ;
            for(int neigh : adjencyList[i]){
                cout << vertexVal[neigh] << " ";
            }
            cout << endl;
        }

    }

    void BFStraversal(int start){
        queue<int> Q;
        bool *visited = new bool[vertices]{false};

        
        int startIndex = getIndex(start);
        if(startIndex == -1) {
        cout << "Invalid start vertex!" << endl;
        return;
        }
        Q.push(startIndex);
        visited[startIndex] = true;


        while (Q.size() > 0){
            int u = Q.front();
            Q.pop();
            cout << vertexVal[u] << " ";
            for( int v : adjencyList[u]){
                if(!visited[v]){
                    visited[v] = true;
                    Q.push(v);
                }
            }
        }
        cout << endl;
    }

    //dfs traversal using recursion
    void DFSTraversalHelper(int source , bool* visited){
        cout << vertexVal[source] << " ";
        visited[source] = true;

        for(int v : adjencyList[source]){
            if(!visited[v]){
                DFSTraversalHelper(v , visited);
            }
        }
    }

    void DFS(){
        int source = 0 ;
        bool* visited = new bool[vertices]{false} ;

        DFSTraversalHelper(source , visited);
        cout << endl;
    }

    void printNeighbours(int value){
        int index = getIndex(value);

        if(index == -1){
            cout << " invalid Index " << endl;
            return;
        }

        for (int neighbour : adjencyList[index]){
            cout << vertexVal[neighbour] << " ";
       }
       cout << endl;
    }

    // DFS using stack
    void DFSstack(int source){
        stack<int> st;
        bool* visited = new bool [vertices]{false};

        int index = getIndex(source);
        if(index == -1){
            cout << "invalid vertex" << endl;
            return;
        }

        st.push(index);
 
        while(!st.empty()){
            int u = st.top();
            st.pop();

            if(!visited[u]){
                visited[u] = true;
                cout << vertexVal[u] << " ";
            }

            for(int neighbour : adjencyList[u]){
                if(!visited[neighbour]){
                    st.push(neighbour);
                }
            }
        }


    }

    //main logic: agr ik node pr travel krhy hain uska parent already visited hai
    //or uska next neighbour bhi visited hai but parent nahi tow
    //it is a BACK EDGE condition which means it has cycle
    bool isCyclicDFS_unDir(int source ,int parent , bool* visited){
        visited[source] = true;

        //yahan hum is source ky neighbours pr travel krhy hain

        for(int v : adjencyList[source]){
            if(!visited[v]){
                if(isCyclicDFS_unDir(v , source, visited)){
                    return true;
                }
            }
            else if(v != parent){
                return true;
            }
        }
        return false;
    }

    bool isCyclicDFS(){
        bool * visited = new bool [vertices]{false};

        for (int i = 0 ; i < vertices ; i++){
            if(!visited[i]){
                if(isCyclicDFS_unDir(i, -1 , visited) ){
                    return true;
                }
            }
        }
        return false;
        
    }

    


};


int main()


{
   Graph g (5);
   g.addVertex(0, 1);
   g.addVertex(1, 2);
   g.addVertex(2, 7);
   g.addVertex(3, 4);
   g.addVertex(4, 5);
   //g.addVertex(8, 9);


   g.addEdge(1 , 2);
   g.addEdge(1 , 5);
   g.addEdge(1 , 7);
   g.addEdge(2 , 5);
   g.addEdge(2 , 7);
   g.addEdge(2 , 4);
   g.addEdge(4 , 5);
   g.addEdge(4 , 9);

   cout<<"after";

  g.printAdjencyList();
   g.BFStraversal(1);

   g.DFS();
   g.DFSstack(1); 
   cout << endl;

   cout << g.isCyclicDFS() << endl;
   cout << g.degree(7);
    

    return 0;
}