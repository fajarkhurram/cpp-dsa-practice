#include <iostream>
using namespace std;

class AdjNode
{
public:
    int vertex;
    AdjNode* next;

    AdjNode(int v)
    {
        vertex = v;
        next = NULL;
    }
};

class VertexNode
{
public:
    int vertexNo;
    VertexNode* next;
    AdjNode* adjList;

    VertexNode(int v)
    {
        vertexNo = v;
        next = NULL;
        adjList = NULL;
    }
};

class Graph
{
    VertexNode* head;

public:

    Graph()
    {
        head = NULL;
    }

    // Insert Vertex
    void insertVertex(int v)
    {
        VertexNode* newNode = new VertexNode(v);

        if(head == NULL)
        {
            head = newNode;
            return;
        }

        VertexNode* curr = head;

        while(curr->next != NULL)
            curr = curr->next;

        curr->next = newNode;
    }

    // Insert Edge
    void insertEdge(int source, int destination)
    {
        VertexNode* curr = head;

        while(curr != NULL)
        {
            if(curr->vertexNo == source)
            {
                AdjNode* newNode = new AdjNode(destination);

                if(curr->adjList == NULL)
                {
                    curr->adjList = newNode;
                }
                else
                {
                    AdjNode* temp = curr->adjList;

                    while(temp->next != NULL)
                        temp = temp->next;

                    temp->next = newNode;
                }

                return;
            }

            curr = curr->next;
        }

        cout << "Source Vertex Not Found!" << endl;
    }

    // Search Vertex
    bool searchVertex(int v)
    {
        VertexNode* curr = head;

        while(curr != NULL)
        {
            if(curr->vertexNo == v)
            {
                cout << "Vertex Found\n";
                return true;
            }

            curr = curr->next;
        }

        cout << "Vertex Not Found\n";
        return false;
    }

    // Search Edge
    bool searchEdge(int source, int destination)
    {
        VertexNode* curr = head;

        while(curr != NULL)
        {
            if(curr->vertexNo == source)
            {
                AdjNode* temp = curr->adjList;

                while(temp != NULL)
                {
                    if(temp->vertex == destination)
                    {
                        cout << "Edge Found\n";
                        return true;
                    }

                    temp = temp->next;
                }

                cout << "Edge Not Found\n";
                return false;
            }

            curr = curr->next;
        }

        cout << "Source Vertex Not Found\n";
        return false;
    }

    // Delete Edge
    void deleteEdge(int source, int destination)
    {
        VertexNode* curr = head;

        while(curr != NULL)
        {
            if(curr->vertexNo == source)
            {
                AdjNode* temp = curr->adjList;
                AdjNode* prev = NULL;

                while(temp != NULL)
                {
                    if(temp->vertex == destination)
                    {
                        if(prev == NULL)
                            curr->adjList = temp->next;
                        else
                            prev->next = temp->next;

                        delete temp;
                        cout << "Edge Deleted\n";
                        return;
                    }

                    prev = temp;
                    temp = temp->next;
                }

                cout << "Edge Not Found\n";
                return;
            }

            curr = curr->next;
        }

        cout << "Source Vertex Not Found\n";
    }

    // Delete Vertex
    void deleteVertex(int v)
    {
        VertexNode* curr = head;
        VertexNode* prev = NULL;

        while(curr != NULL)
        {
            if(curr->vertexNo == v)
            {
                // Delete adjacency list
                AdjNode* temp = curr->adjList;

                while(temp != NULL)
                {
                    AdjNode* del = temp;
                    temp = temp->next;
                    delete del;
                }

                if(prev == NULL)
                    head = curr->next;
                else
                    prev->next = curr->next;

                delete curr;

                cout << "Vertex Deleted\n";
                return;
            }

            prev = curr;
            curr = curr->next;
        }

        cout << "Vertex Not Found\n";
    }

    // Display Graph
    void displayGraph()
    {
        VertexNode* curr = head;

        cout << "\nAdjacency List\n\n";

        while(curr != NULL)
        {
            cout << curr->vertexNo << " -> ";

            AdjNode* temp = curr->adjList;

            while(temp != NULL)
            {
                cout << temp->vertex << " -> ";
                temp = temp->next;
            }

            cout << "NULL" << endl;

            curr = curr->next;
        }
    }
};

int main()
{
    Graph g;

    int choice;

    do
    {
        cout << "\n===== GRAPH MENU =====\n";
        cout << "1. Insert Vertex\n";
        cout << "2. Insert Edge\n";
        cout << "3. Delete Vertex\n";
        cout << "4. Delete Edge\n";
        cout << "5. Search Vertex\n";
        cout << "6. Search Edge\n";
        cout << "7. Display Graph\n";
        cout << "8. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        int v, s, d;

        switch(choice)
        {
        case 1:
            cout << "Enter Vertex: ";
            cin >> v;
            g.insertVertex(v);
            break;

        case 2:
            cout << "Source Vertex: ";
            cin >> s;

            cout << "Destination Vertex: ";
            cin >> d;

            g.insertEdge(s,d);
            break;

        case 3:
            cout << "Vertex to Delete: ";
            cin >> v;

            g.deleteVertex(v);
            break;

        case 4:
            cout << "Source Vertex: ";
            cin >> s;

            cout << "Destination Vertex: ";
            cin >> d;

            g.deleteEdge(s,d);
            break;

        case 5:
            cout << "Vertex to Search: ";
            cin >> v;

            g.searchVertex(v);
            break;

        case 6:
            cout << "Source Vertex: ";
            cin >> s;

            cout << "Destination Vertex: ";
            cin >> d;

            g.searchEdge(s,d);
            break;

        case 7:
            g.displayGraph();
            break;

        case 8:
            cout << "Program Ended\n";
            break;

        default:
            cout << "Invalid Choice\n";
        }

    }while(choice != 8);

    return 0;
}