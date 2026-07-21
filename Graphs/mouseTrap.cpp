#include<iostream>
#include<queue>
#include<cstdlib>


using namespace std;

int dr[8]={-1,-1,-1,0,0,1,1,1};   // row movement
int dc[8]={-1,0,1,-1,1,-1,0,1};   // column movement

struct AdjNode
{
    int vertex;          // connected vertex ka index
    AdjNode *next;       // next neighbour

    AdjNode(int v)
    {
        vertex=v;        // vertex save kr rhy hain
        next=NULL;       // abhi next neighbour nahi hai
    }
};

struct Vertex
{
    int row,col;         // maze wali original position

    AdjNode *head;       // adjacency list ka start

    Vertex()
    {
        row=-1;          // default value
        col=-1;
        head=NULL;       // abhi koi neighbour nahi
    }
};

class Graph
{
public:

    int totalVertices;    // graph mein total vertices
    Vertex *vertices;     // vertices ki array

    Graph(int size)
    {
        totalVertices=size;           // total vertices save
        vertices=new Vertex[size];    // dynamic array bana di
    }

    void setVertex(int index,int r,int c)
    {
        vertices[index].row=r;        // row save
        vertices[index].col=c;        // column save
    }

    void addEdge(int src,int dest)
    {
        AdjNode *newNode=new AdjNode(dest);   // naya neighbour bnao

        newNode->next=vertices[src].head;     // pehle wale head se connect

        vertices[src].head=newNode;           // new node ko head bana do
    }

    void printGraph()
    {
        cout<<"\n===== Adjacency List =====\n";

        for(int i=0;i<totalVertices;i++)
        {
            cout<<"("<<vertices[i].row<<","<<vertices[i].col<<") -> ";

            AdjNode *temp=vertices[i].head;   // head se traversal start

            while(temp!=NULL)
            {
                int v=temp->vertex;           // connected vertex nikalo

                cout<<"("<<vertices[v].row<<","<<vertices[v].col<<") ";

                temp=temp->next;              // next neighbour pr jao
            }

            cout<<endl;
        }
    }

// Maze ko random values se fill krna

void generateMaze(int maze[][10], int rows, int cols)
{
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            maze[i][j]=rand()%2;      // random 0 ya 1
        }
    }

    maze[0][0]=0;                     // start open
    maze[rows-1][cols-1]=0;           // destination open
}

// Maze print krna

void printMaze(int maze[][10], int rows, int cols)
{
    cout<<"\nGenerated Maze\n\n";

    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            cout<<maze[i][j]<<" ";
        }

        cout<<endl;
    }
}

// Total open cells (0) count krna

int countVertices(int maze[][10], int rows, int cols)
{
    int count=0;

    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            if(maze[i][j]==0)
            {
                count++;
            }
        }
    }

    return count;
}

// Har open cell ko vertex number assign krna

void createMapping(int maze[][10], int mapping[][10], int rows, int cols)
{
    int index=0;

    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            if(maze[i][j]==0)
            {
                mapping[i][j]=index;     // vertex number save
                index++;
            }
            else
            {
                mapping[i][j]=-1;        // blocked cell
            }
        }
    }
}

// Mapping print krna

void printMapping(int mapping[][10], int rows, int cols)
{
    cout<<"\nVertex Mapping\n\n";

    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            cout<<mapping[i][j]<<"\t";
        }

        cout<<endl;
    }
}


};