#include <fstream>
#include <iostream>

#include "graph.h"

static const std::string kGraphFilename = "graph.txt";

struct Configuration {
  int edge_count = 0;
  int vertex_count = 0;
  std::stack<std::pair<int, int>> edges;
  int from = 0;
};

auto Configure() -> Configuration;

auto main() -> int {
  SGraph *graph_p = nullptr;

  try {
    auto [edge_count, vertex_count, edges, from] = Configure();
    graph_p = new SGraph(vertex_count);
    for (int i = 0; i < edge_count; i++) {
      graph_p->AddEdge(edges.top().first, edges.top().second);
      edges.pop();
    }
    auto path_lenth_list = graph_p->ShortestPathToAll(from);
    for (auto length : path_lenth_list) {
      std::cout << length << std::endl;
    }
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  delete graph_p;

  return 0;
}

auto Configure() -> Configuration {
  std::ifstream ifs(kGraphFilename);
  if (!ifs.is_open()) {
    throw std::runtime_error("Failed to open file " + kGraphFilename);
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
  ifs >> config.from;

  return config;
}
