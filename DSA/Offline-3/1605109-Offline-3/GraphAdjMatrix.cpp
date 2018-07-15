// If you kopy
// and submit this kode
// I will find you
// and I will kiss you

// 1605109
// May 11 2018 1944

#include<cstdio>
#include<cstdlib>
#define NULL_VALUE -999999
#define INFINITY 999999
#define WHITE 1
#define GREY 2
#define BLACK 3

class Queue
{
    int queueInitSize ;
    int queueMaxSize;
    int * data;
    int length;
    int front;
    int rear;
public:
    Queue();
    ~Queue();
    void enqueue(int item); //insert item in the queue
    int dequeue(); //returns the item according to FIFO
    bool empty(); //return true if Queue is empty
};

Queue::Queue()
{
    queueInitSize = 2 ;
    queueMaxSize = queueInitSize;
    data = new int[queueMaxSize] ; //allocate initial memory
    length = 0 ;
    front = 0;
    rear = 0;
}


void Queue::enqueue(int item)
{
	if (length == queueMaxSize)
	{
		int * tempData ;
		//allocate new memory space for tempList
		queueMaxSize = 2 * queueMaxSize ;
		tempData = new int[queueMaxSize] ;
		int i, j;
		j = 0;
		for( i = rear; i < length ; i++ )
		{
			tempData[j++] = data[i] ; //copy items from rear
		}
		for( i = 0; i < rear ; i++ )
		{
			tempData[j++] = data[i] ; //copy items before rear
		}
		rear = 0 ;
		front = length ;
		delete[] data ; //free the memory allocated before
		data = tempData ; //make list to point to new memory
	}

	data[front] = item ; //store new item
	front = (front + 1) % queueMaxSize ;
	length++ ;
}


bool Queue::empty()
{
	if(length == 0) return true ;
	else return false ;
}


int Queue::dequeue()
{
	if(length == 0) return NULL_VALUE ;
	int item = data[rear] ;
	rear = (rear + 1) % queueMaxSize ;
	length-- ;
	return item ;
}


Queue::~Queue()
{
    if(data) delete[] data; //deallocate memory
    data = 0; //set to NULL
}

//****************Queue class ends here************************


//******************Graph class starts here**************************
class Graph
{
	int nVertices, nEdges ;
	bool directed ;
	int ** matrix ; //adjacency matrix to store the graph
	//define other variables required for bfs such as color, parent, and dist
	//you must use pointers and dynamic allocation
	int *color, *parent, *distance;
	int *discovery, *finish;
	int *degree;
	int dfstime;

public:
	Graph(bool dir = false);
	~Graph();
	void setnVertices(int n);
	void addEdge(int u, int v);
	void removeEdge(int u, int v);
	bool isEdge(int u, int v);
    int getDegree(int u);
    bool hasCommonAdjacent(int u, int v);
    int getDist(int u, int v);
    void printGraph();
	void bfs(int source); //will run bfs in the graph
	void dfs();
	void dfs_visit(int source);
};


Graph::Graph(bool dir)
{
	nVertices = 0 ;
	nEdges = 0 ;
	matrix = 0 ;
	directed = dir ; //set direction of the graph
	//define other variables to be initialized
	color = 0;
	parent = 0;
	distance = 0;
	discovery = 0;
	finish = 0;
	degree = 0;
}

void Graph::setnVertices(int n)
{
	this->nVertices = n ;

	//allocate space for the matrix
    matrix = new int*[nVertices];
    for(int i=0;i<nVertices;i++)
    {
        matrix[i] = new int[nVertices];
        for(int j=0;j<nVertices;j++)
            matrix[i][j] = 0; //initialize the matrix cells to 0
    }
    
    if(color != 0) delete[] color;
	color = new int[nVertices];
	if(parent != 0) delete[] parent;
	parent = new int[nVertices];
	if(distance != 0) delete[] distance;
	distance = new int[nVertices];
	if(discovery != 0) delete[] discovery;
	discovery = new int[nVertices];
	if(finish != 0) delete[] finish;
	finish = new int[nVertices];
	if(degree != 0) delete[] degree;
	degree = new int[nVertices];
	for(int i=0; i<nVertices; ++i) degree[i] = 0;
}

void Graph::addEdge(int u, int v)
{
    //write your code here
    if(u<0 || u>=nVertices || v<0 || v>=nVertices) return;
    this->nEdges++;
    matrix[u][v] = 1;
    if(!directed) matrix[v][u] = 1;
    ++degree[u];
    ++degree[v];
}

void Graph::removeEdge(int u, int v)
{
    //write this function
    if(u<0 || v<0 || u>=nVertices || v>=nVertices) return; //vertex out of range
    if(!isEdge(u, v)) return ;
    
    this->nEdges--;
    matrix[u][v] = 0;
    if(!directed) matrix[v][u] = 0;
    --degree[u];
    --degree[v];
}

bool Graph::isEdge(int u, int v)
{
    //returns true if (u,v) is an edge, otherwise should return false
    if(u<0 || v<0 || u>=nVertices || v>=nVertices) return false; //vertex out of range
    return (matrix[u][v] == 1);
}

int Graph::getDegree(int u)
{
    //returns the degree of vertex u
    if(u<0 or u>=nVertices) return 0; //vertex out of range
    return degree[u];
}

bool Graph::hasCommonAdjacent(int u, int v)
{
    //returns true if vertices u and v have common adjacent vertices
    if(u<0 || v<0 || u>=nVertices || v>=nVertices) return false; //vertex out of range
    
    for(int i=0; i<nVertices; ++i) {
    	if(i == u or i == v or matrix[u][i] == 0) continue;
    	if(matrix[v][i] == 1) return true;
    }
    return false;
}

void Graph::bfs(int source)
{
    //complete this function
    //initialize BFS variables
    for(int i=0; i<nVertices; i++)
    {
        color[i] = WHITE ;
        parent[i] = -1 ;
        distance[i] = INFINITY ;
    }
    Queue q ;
    color[source] = GREY;
    distance[source] = 0 ;
    q.enqueue(source) ;
    while( !q.empty() )
    {
        //complete this part
        int u = q.dequeue();
        for(int v=0; v<nVertices; ++v) {
        	if(matrix[u][v] == 0) continue;
        	if(color[v] == WHITE) {
        		color[v] = GREY;
        		distance[v] = distance[u] + 1;
        		parent[v] = u;
        		q.enqueue(v);
        	}
        }
        color[u] = BLACK;
    }
}

void Graph::dfs()
{
    //write this function
    for(int i=0; i<nVertices; ++i) {
    	color[i] = WHITE;
    	parent[i] = -1;
    }
    dfstime = 0;
    
    for(int i=0; i<nVertices; ++i) {
    	if(color[i] == WHITE) dfs_visit(i);
    }
}

void Graph::dfs_visit(int source)
{
	// recursive fun
	++dfstime;
	discovery[source] = dfstime;
	color[source] = GREY;
	
	for(int v=0; v<nVertices; ++v) {
		if(matrix[source][v] == 1 and color[v] == WHITE) {
			parent[v] = source;
			dfs_visit(v);
		}
	}
	
	color[source] = BLACK;
	++dfstime;
	finish[source] = dfstime;
}

int Graph::getDist(int u, int v)
{
    //returns the shortest path distance from u to v
    //must call bfs using u as the source vertex, then use distance array to find the distance
    if(u<0 || v<0 || u>=nVertices || v>=nVertices) return INFINITY; //vertex out of range
    bfs(u);
    return distance[v];
}


void Graph::printGraph()
{
    printf("\nNumber of vertices: %d, Number of edges: %d\n", nVertices, nEdges);
    for(int i=0;i<nVertices;i++)
    {
        printf("%d:", i);
        for(int j=0; j<nVertices;j++)
        {
            if(matrix[i][j]==1)
                printf(" %d", j);
        }
        printf("\n");
    }
}

Graph::~Graph()
{
    //write your destructor here
    if(matrix != 0) {
    	for(int i=0; i<nVertices; ++i) {
    		if(matrix[i] != 0) delete[] matrix[i];
    		matrix[i] = 0;
    	}
    	delete[] matrix;
    }
    matrix = 0;
    if(color != 0) delete[] color;
	color = 0;
	if(parent != 0) delete[] parent;
	parent = 0;
	if(distance != 0) delete[] distance;
	distance = 0;
	if(discovery != 0) delete[] discovery;
	discovery = 0;
	if(finish != 0) delete[] finish;
	finish = 0;
	if(degree != 0) delete[] degree;
	degree = 0;
}


//**********************Graph class ends here******************************


//******main function to test your code*************************
int main(void)
{
    int n;
    Graph g;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    g.setnVertices(n);

    while(1)
    {
        printf("1. Add edge. 2. Remove edge. 3. Is edge. 4. Has common adjacent. \n");
        printf("5. Get Distance. 6. DFS. 7. Print Graph  8. Exit.\n");

        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            g.addEdge(u, v);
        }
        else if(ch==2)
        {
			int u, v;
            scanf("%d%d", &u, &v);
            g.removeEdge(u, v);
        }
        else if(ch==3)
        {
			int u, v;
            scanf("%d%d", &u, &v);
            if(g.isEdge(u, v)) printf("Edge exists.\n");
            else printf("Edge doesn't exist.\n");
        }
        else if(ch == 4)
        {
        	int u, v;
            scanf("%d%d", &u, &v);
            if(g.hasCommonAdjacent(u, v)) printf("Has common adjacent.\n");
            else printf("No common adjacent.\n");
        }
        else if(ch==5)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            printf("Distance: %d\n", g.getDist(u, v));
        }
        else if(ch==6)
        {
            g.dfs();
        }
        else if(ch == 7)
        {
        	g.printGraph();
        }
        else if(ch == 8) 
        {
        	break;
        }
    }
	
	return 0;
}
