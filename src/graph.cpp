//
// Created by Micha on 18.03.2025.
//

#include "graph.h"

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

SGraph SGraph::ShortestPath(int v_from, int v_to) const {

}

