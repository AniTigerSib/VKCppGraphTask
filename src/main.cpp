#include <fstream>
#include <iostream>

#include "graph.h"

static const std::string graph_filename = "graph.txt";

struct Configuration {
    int edge_count = 0;
    int vertex_count = 0;
    std::stack<std::pair<int, int>> edges;
    int from = 0;
    int to = 0;
};

Configuration Configure();

int main() {
    SGraph *graph_p = nullptr;

    try {
        auto [edge_count, vertex_count, edges, from, to] = Configure();
        graph_p = new SGraph(vertex_count);
        for (int i = 0; i < edge_count; i++) {
            graph_p->AddEdge(edges.top().first, edges.top().second);
            edges.pop();
        }
        // graph_p->Print();
        auto res = graph_p->ShortestPath(from, to);
        std::cout << from << std::endl;
        while (!res.empty()) {
            std::cout << res.top() << std::endl;
            res.pop();
        }
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    delete graph_p;

    return 0;
}

Configuration Configure() {
    std::ifstream ifs(graph_filename);
    if (!ifs.is_open()) {
        throw std::runtime_error("Failed to open file " + graph_filename);
    }
    Configuration config;
    std::string line;
    ifs >> config.vertex_count;
    ifs >> config.edge_count;

    for (int i = 0; i < config.edge_count; i++) {
        std::pair<int, int> edge;
        ifs >> edge.first >> edge.second;
        config.edges.push(edge);
    }
    ifs >> config.from >> config.to;

    return config;
}
