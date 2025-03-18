//
// Created by Micha on 18.03.2025.
//

#include "graph.h"

#include <deque>
#include <stack>

Matrix::Matrix(const int size) {
    matrix_.resize(size);
    for (int i = 0; i < size; i++) {
        matrix_[i].resize(size);
    }
}

Matrix::Matrix(const Matrix &matrix) {
    matrix_ = matrix.matrix_;
}

Matrix::Matrix(Matrix &&matrix) noexcept {
    matrix_ = std::move(matrix.matrix_);
}

void Matrix::Print() const {
    for (const auto & i : matrix_) {
        for (const auto & j : i) {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
}

void SGraph::AddEdge(const int v0, const int v1) {
    this->Set(v0, v1, 1);
    this->Set(v1, v0, 1);
}

void SGraph::DeleteEdge(const int v0, const int v1) {
    this->Set(v0, v1, 0);
    this->Set(v1, v0, 0);
}

std::stack<int> SGraph::ShortestPath(const int v_from, const int v_to) const {
    std::vector<int> length(matrix_.size(), INT_MAX);
    std::vector<int> mark(matrix_.size(), 0);
    std::vector<int> history(matrix_.size(), -1);
    std::stack<int> result;

    int vertex = v_from;
    length[vertex] = 0;
    while (vertex != v_to && vertex != -1) {
        mark[vertex] = 1;
        for (int i = 0; i < matrix_.size() && matrix_[vertex][i]; i++) {
            if (mark[i] == 0 && length[i] > length[vertex] + 1) {
                length[i] = length[vertex] + 1;
                history[i] = vertex;
            }
        }
        int min = INT_MAX;
        vertex = -1;
        for (int i = 0; i < matrix_.size(); i++) {
            if (mark[i] == 0 && length[i] < min) {
                vertex = i;
                min = length[i];
            }
        }
    }

    if (vertex == -1) {
        throw SGraphException("SGraph::ShortestPath: No path exists");
    }

    while (vertex != v_from) {
        result.push(vertex);
        vertex = history[vertex];
    }

    return result;
}
