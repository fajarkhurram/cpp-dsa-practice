#include <iostream>
#include <list>
#include <queue>
#include <stack>
using namespace std;

class Graph
{
public:
    int vertices;
    int *vertexVal;
    list<int> *adjacencyList;

    // Constructor
    Graph(int vertices)
    {
        this->vertices = vertices;
        adjacencyList = new list<int>[vertices];
        vertexVal = new int[vertices];
    }

    // Add Vertex
    void addVertex(int index, int value)
    {
        if (index >= vertices)
        {
            cout << "Invalid Index!" << endl;
            return;
        }

        vertexVal[index] = value;
    }

    // Find Index of Vertex Value
    int getIndex(int value)
    {
        for (int i = 0; i < vertices; i++)
        {
            if (vertexVal[i] == value)
                return i;
        }

        return -1;
    }

    // Add Directed Edge
    void addEdge(int from, int to)
    {
        int i1 = getIndex(from);
        int i2 = getIndex(to);

        if (i1 == -1 || i2 == -1)
        {
            cout << "Invalid Vertex!" << endl;
            return;
        }

        adjacencyList[i1].push_back(i2);
    }

    // Print Graph
    void printAdjacencyList()
    {
        cout << "\nAdjacency List\n";

        for (int i = 0; i < vertices; i++)
        {
            cout << vertexVal[i] << " : ";

            for (int neighbour : adjacencyList[i])
                cout << vertexVal[neighbour] << " ";

            cout << endl;
        }
    }

    // Out Degree
    int outDegree(int value)
    {
        int index = getIndex(value);

        if (index == -1)
            return -1;

        return adjacencyList[index].size();
    }

    // In Degree
    int inDegree(int value)
    {
        int index = getIndex(value);

        if (index == -1)
            return -1;

        int count = 0;

        for (int i = 0; i < vertices; i++)
        {
            for (int neighbour : adjacencyList[i])
            {
                if (neighbour == index)
                    count++;
            }
        }

        return count;
    }

    // BFS
    void BFS(int start)
    {
        int index = getIndex(start);

        if (index == -1)
        {
            cout << "Invalid Start Vertex\n";
            return;
        }

        bool *visited = new bool[vertices]{false};

        queue<int> q;

        visited[index] = true;
        q.push(index);

        cout << "BFS : ";

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            cout << vertexVal[u] << " ";

            for (int v : adjacencyList[u])
            {
                if (!visited[v])
                {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }

        cout << endl;
    }

    // Recursive DFS Helper
    void DFSHelper(int source, bool visited[])
    {
        visited[source] = true;

        cout << vertexVal[source] << " ";

        for (int v : adjacencyList[source])
        {
            if (!visited[v])
                DFSHelper(v, visited);
        }
    }

    // Recursive DFS
    void DFS(int start)
    {
        int index = getIndex(start);

        if (index == -1)
        {
            cout << "Invalid Vertex\n";
            return;
        }

        bool *visited = new bool[vertices]{false};

        cout << "DFS (Recursive): ";

        DFSHelper(index, visited);

        cout << endl;
    }

    // DFS using Stack
    void DFSStack(int start)
    {
        int index = getIndex(start);

        if (index == -1)
        {
            cout << "Invalid Vertex\n";
            return;
        }

        bool *visited = new bool[vertices]{false};

        stack<int> st;

        st.push(index);

        cout << "DFS (Stack): ";

        while (!st.empty())
        {
            int u = st.top();
            st.pop();

            if (!visited[u])
            {
                visited[u] = true;

                cout << vertexVal[u] << " ";

                for (int v : adjacencyList[u])
                {
                    if (!visited[v])
                        st.push(v);
                }
            }
        }

        cout << endl;
    }

    // Print Neighbours
    void printNeighbours(int value)
    {
        int index = getIndex(value);

        if (index == -1)
        {
            cout << "Invalid Vertex\n";
            return;
        }

        cout << "Neighbours of " << value << " : ";

        for (int neighbour : adjacencyList[index])
            cout << vertexVal[neighbour] << " ";

        cout << endl;
    }

    // Cycle Detection Helper (Directed)
    bool isCyclicHelper(int source, bool visited[], bool recStack[])
    {
        visited[source] = true;
        recStack[source] = true;

        for (int v : adjacencyList[source])
        {
            if (!visited[v])
            {
                if (isCyclicHelper(v, visited, recStack))
                    return true;
            }
            else if (recStack[v])
            {
                return true;
            }
        }

        recStack[source] = false;

        return false;
    }

    // Cycle Detection
    bool isCyclic()
    {
        bool *visited = new bool[vertices]{false};
        bool *recStack = new bool[vertices]{false};

        for (int i = 0; i < vertices; i++)
        {
            if (!visited[i])
            {
                if (isCyclicHelper(i, visited, recStack))
                    return true;
            }
        }

        return false;
    }
};

int main()
{
    Graph g(5);

    g.addVertex(0, 1);
    g.addVertex(1, 2);
    g.addVertex(2, 3);
    g.addVertex(3, 4);
    g.addVertex(4, 5);

    // Directed Edges
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(4, 5);

    // Uncomment to create cycle
    g.addEdge(5, 2);

    g.printAdjacencyList();

    cout << endl;

    g.BFS(1);

    g.DFS(1);

    g.DFSStack(1);

    cout << endl;

    g.printNeighbours(1);

    cout << "Out Degree of 1 = " << g.outDegree(1) << endl;

    cout << "In Degree of 4 = " << g.inDegree(4) << endl;

    if (g.isCyclic())
        cout << "Graph Contains Cycle" << endl;
    else
        cout << "Graph Does Not Contain Cycle" << endl;

    return 0;
}