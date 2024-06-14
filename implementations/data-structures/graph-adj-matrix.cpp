#include <iostream>
#include <queue>
#include <vector>

#include "graph.h"

using namespace std;

void Assert(bool expr, string msg) {
    if (!expr) {
        throw runtime_error(msg);
    }
}

// graph implementation using adjacency matrix
const int UNVISITED = 0;
const int VISITED = 1;
class Graphm final : public Graph {
   private:
    int num_vertex, num_edges;
    bool *mark;
    int **matrix;
    void Init(int n) {
        num_vertex = n;
        num_edges = 0;
        mark = new bool[n];
        matrix = (int **)new int *[n];
        for (int i = 0; i < num_vertex; i++) {
            matrix[i] = new int[n];
        }
        for (int i = 0; i < num_vertex; i++) {
            for (int j = 0; j < num_vertex; j++) {
                matrix[i][j] = 0;
            }
        }
    }

   public:
    Graphm(int num_vertices) {
        Init(num_vertices);
    }
    ~Graphm() {
        delete[] mark;
        for (int i = 0; i < num_vertex; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    int n() { return num_vertex; };
    int e() { return num_edges; };

    int first(int v) {
        for (int i = 0; i < num_vertex; i++) {
            if (matrix[v][i] != 0) return i;
        }
        return num_vertex;
    }

    // next neighbour after w
    int next(int v, int w) {
        for (int i = w + 1; i < num_vertex; i++) {
            if (matrix[v][i] != i) return i;
        }
        return num_vertex;
    }

    void set_edge(int i, int j, int weight) {
        Assert(weight > 0, "Weights must be positive");
        if (matrix[i][j] == 0) num_edges++;
        matrix[i][j] = weight;
    };

    void del_edge(int i, int j) {
        if (matrix[i][j] != 0) num_edges--;
        matrix[i][j] = 0;
    }

    bool is_edge(int i, int j) {
        return matrix[i][j] != 0;
    }

    int weight(int v1, int v2) {
        return matrix[v1][v2];
    }

    void set_mark(int v, int val) {
        mark[v] = val;
    }

    int get_mark(int v) {
        return mark[v];
    }
};
void dfs(Graph *G, int v) {
    // preprocessing
    // doesn't care whether v is actually in the graph
    G->set_mark(v, VISITED);
    for (int w = G->first(v); w < G->n(); w = G->next(v, w)) {
        if (G->get_mark(w) == UNVISITED) {
            dfs(G, w);
        }
    }
    cout << "DFS: " << v << '\n';
    // postprocessing
    // the vertices actually in the graph
}

void bfs_help(Graph *G, int start, queue<int> *q) {
    int v, w;
    q->push(start);
    G->set_mark(start, VISITED);
    while (!q->empty()) {
        int v = q->front();
        q->pop();
        cout << "BFS: " << v << "\n";
        for (w = G->first(v); w < G->n(); w = G->next(v, w)) {
            if (G->get_mark(w) == UNVISITED) {
                G->set_mark(w, VISITED);
                q->push(w);
            }
        }
    }
}

void bfs(Graph *g, int start) {
    queue<int> q;
    return bfs_help(g, start, &q);
}

void graph_traverse(Graph *g, void (*visitor)(Graph *g, int v)) {
    int v;
    for (v = 0; v < g->n(); v++) {
        g->set_mark(v, UNVISITED);
    }
    for (v = 0; v < g->n(); v++) {
        if (g->get_mark(v) == UNVISITED) {
            visitor(g, v);
        }
    }
}

int main() {
    auto g = new Graphm(6);

    g->set_edge(2, 3, 1);
    g->set_edge(3, 5, 2);
    g->set_edge(0, 1, 3);
    g->set_edge(0, 2, 4);
    g->set_edge(0, 3, 5);
    g->set_edge(4, 2, 6);
    g->set_edge(5, 4, 7);

    queue<int> q;

    graph_traverse(g, dfs);
    graph_traverse(g, bfs);

    return 0;
}