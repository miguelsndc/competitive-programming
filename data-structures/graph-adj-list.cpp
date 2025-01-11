
#include <iostream>
#include <list>

#include "graph.h"

using namespace std;

void Assert(bool expr, string msg) {
    if (!expr) {
        throw runtime_error(msg);
    }
}

class Edge {
    int v, wt;

   public:
    Edge(int vt = -1, int wgt = -1) {
        v = vt;
        wt = wgt;
    }
    int weight() {
        return wt;
    }
    int vertex() {
        return v;
    }
};

// graph implementation using adjacency matrix
class Graphl : public Graph {
   private:
    const int UNVISITED = 0;
    const int VISITED = 1;
    int num_vertex, num_edges;
    bool *mark;
    list<Edge> **adj_list;
    void Init(int n) {
        num_vertex = n;
        num_edges = 0;
        mark = new bool[n];
        adj_list = new list<Edge> *[n];
        for (int i = 0; i < num_vertex; i++) {
            adj_list[i] = new list<Edge>();
        }
    }

   public:
    Graphl(int num_vertices) {
        Init(num_vertices);
    }
    ~Graphl() {
        delete[] mark;
        for (int i = 0; i < num_vertex; i++) {
            delete adj_list[i];
        }
        delete[] adj_list;
    }

    int n() { return num_vertex; };
    int e() { return num_edges; };

    int first(int v) {
        if (adj_list[v]->size() == 0) {
            return num_vertex;
        }
        Edge f = adj_list[v]->front();
        return f.vertex();
    }

    // next neighbour after w
    int next(int v, int w) {
        for (auto it = adj_list[v]->begin(); it != adj_list[v]->end(); ++it) {
            if (it->vertex() == w) {
                ++it;
                if (it != adj_list[v]->end()) {
                    return it->vertex();
                } else {
                    return num_vertex;
                }
            }
        }
        return num_vertex;
    }

    void set_edge(int i, int j, int weight) {
        Assert(weight > 0, "Weights must be positive");
        Edge ed(j, weight);
        auto it = adj_list[i]->begin();
        for (; it != adj_list[i]->end(); ++it) {
            if (it->vertex() == j) {
                adj_list[i]->remove((*it));
                adj_list[i]->insert(it, ed);
                return;
            } else if (it->vertex() > j) {
                break;
            }
        }
        adj_list[i]->insert(it, ed);
        num_edges++;
    };

    void del_edge(int i, int j) {
        auto it = adj_list[i]->begin();
        for (; it != adj_list[i]->end(); ++it) {
            if (it->vertex() == j) {
                break;
            }
        }
        adj_list[i]->remove((*it));
    }

    bool is_edge(int i, int j) {
        for (auto it = adj_list[i]->begin(); it != adj_list[i]->end(); ++it) {
            if (it->vertex() == j) {
                return true;
            }
        }
        return false;
    }

    int weight(int v1, int v2) {
        for (auto it = adj_list[v1]->begin(); it != adj_list[v1]->end(); ++it) {
            if (it->vertex() == v2) {
                return it->weight();
            }
        }
        return 0;
    }

    void set_mark(int v, int val) {
        mark[v] = val;
    }

    int get_mark(int v) {
        return mark[v];
    }
};