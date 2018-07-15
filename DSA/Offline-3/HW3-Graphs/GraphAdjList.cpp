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

//****************Dynamic ArrayList class based************************
class ArrayList
{
	int * list;
	int length ;
	int listMaxSize ;
	int listInitSize ;
public:
	ArrayList() ;
	~ArrayList() ;
	int searchItem(int item) ;
    void insertItem(int item) ;
	void removeItem(int item) ;
	void removeItemAt(int item);
	int getItem(int position) ;
	int getLength();
	bool empty();
	void printList();
} ;


ArrayList::ArrayList()
{
	listInitSize = 2 ;
	listMaxSize = listInitSize ;
	list = new int[listMaxSize] ;
	length = 0 ;
}

void ArrayList::insertItem(int newitem)
{
	int * tempList ;
	if (length == listMaxSize)
	{
		//allocate new memory space for tempList
		listMaxSize = 2 * listMaxSize ;
		tempList = new int[listMaxSize] ;
		int i;
        for( i = 0; i < length ; i++ )
        {
            tempList[i] = list[i] ; //copy all items from list to tempList
        }
        delete[] list ; //free the memory allocated before
        list = tempList ; //make list to point to new memory
	};

	list[length] = newitem ; //store new item
	length++ ;
}

int ArrayList::searchItem(int item)
{
	int i = 0;
	for (i = 0; i < length; i++)
	{
		if( list[i] == item ) return i;
	}
	return NULL_VALUE;
}

void ArrayList::removeItemAt(int position) //do not preserve order of items
{
	if ( position < 0 || position >= length ) return ; //nothing to remove
	list[position] = list[length-1] ;
	length-- ;
}


void ArrayList::removeItem(int item)
{
	int position;
	position = searchItem(item) ;
	if ( position == NULL_VALUE ) return ; //nothing to remove
	removeItemAt(position) ;
}


int ArrayList::getItem(int position)
{
	if(position < 0 || position >= length) return NULL_VALUE ;
	return list[position] ;
}

int ArrayList::getLength()
{
	return length ;
}

bool ArrayList::empty()
{
    if(length==0)return true;
    else return false;
}

void ArrayList::printList()
{
    int i;
    for(i=0;i<length;i++)
        printf("%d ", list[i]);
    printf("Current size: %d, current length: %d\n", listMaxSize, length);
}

ArrayList::~ArrayList()
{
    if(list) delete [] list;
    list = 0 ;
}

//******************ArrayList class ends here*************************

//******************Graph class starts here**************************
class Graph
{
	int nVertices, nEdges ;
	bool directed ;
	ArrayList  * adjList ;
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
	void dfs(); //will run dfs in the graph
	void dfs_visit(int source);	// the recursive fun
};


Graph::Graph(bool dir)
{
	nVertices = 0 ;
	nEdges = 0 ;
	adjList = 0 ;
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
	if(adjList!=0) delete[] adjList ; //delete previous list
	adjList = new ArrayList[nVertices] ;
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
    if(u<0 || v<0 || u>=nVertices || v>=nVertices) return; //vertex out of range
    this->nEdges++ ;
	adjList[u].insertItem(v) ;
	if(!directed) adjList[v].insertItem(u) ;
	++degree[u];
	++degree[v];
}

void Graph::removeEdge(int u, int v)
{
    //write this function
    if(u<0 || v<0 || u>=nVertices || v>=nVertices) return; //vertex out of range
    if(!isEdge(u, v)) return ;
    
    this->nEdges--;
    adjList[u].removeItem(v);
    if(!directed) adjList[v].removeItem(u);
    --degree[u];
    --degree[v];
}

bool Graph::isEdge(int u, int v)
{
    //returns true if (u,v) is an edge, otherwise should return false
    if(u<0 || v<0 || u>=nVertices || v>=nVertices) return false; //vertex out of range
    if(adjList[u].searchItem(v) == NULL_VALUE) return false;
    return true;
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
    
    bool *marked = new bool[nVertices];
    for(int i=0; i<nVertices; ++i) marked[i] = false;
    for(int i=0; i<adjList[u].getLength(); ++i) {
    	int tv = adjList[u].getItem(i);
    	marked[tv] = true;
    }
    
    for(int i=0; i<adjList[v].getLength(); ++i) {
    	int tu = adjList[v].getItem(i);
    	if(marked[tu]) {
    		delete[] marked;
    		return true;
    	}
    }
    delete[] marked;
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
        for(int i=0; i<adjList[u].getLength(); ++i) {
        	int v = adjList[u].getItem(i);
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
	
	for(int i=0; i<adjList[source].getLength(); ++i) {
		int v = adjList[source].getItem(i);
		if(color[v] == WHITE) {
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
        for(int j=0; j<adjList[i].getLength();j++)
        {
            printf(" %d", adjList[i].getItem(j));
        }
        printf("\n");
    }
}

Graph::~Graph()
{
    //write your destructor here
    if(adjList!=0) delete[] adjList ; //delete previous list
	adjList = 0;
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
