
#ifndef GRAPH_BASE_CLASS
#define GRAPH_BASE_CLASS
#endif

class Graph {
   private:
    void operator=(const Graph&) {}  // protects assignment
    Graph(const Graph&){};           // protects copy constructor
   public:
    Graph(){};

    virtual void Init(int n) = 0;  // initialize a graph of n vertices

    // number of vertices and edges
    virtual int n() = 0;
    virtual int e() = 0;

    // return v's first neighbour
    virtual int first(int v) = 0;
    // return v's next neighbour
    virtual int next(int v, int w) = 0;
    // i, j: the vertices
    // weight
    virtual void set_edge(int i, int j, int weight) = 0;
    // some com o edge
    virtual void del_edge(int i, int j) = 0;
    // determines if the edge is in the graph
    // e.g if the edge (i, j) has a non-zero weight
    virtual bool is_edge(int i, int j) = 0;
    // return the weight of the edge (v1, v2) or zero if it doesn't exist;
    virtual int weight(int v1, int v2) = 0;
    // gets and sets the mark value for a vertex
    virtual void set_mark(int v, int w) = 0;
    virtual int get_mark(int v) = 0;
};