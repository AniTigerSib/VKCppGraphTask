//
// Created by Micha on 17.03.2025.
//

#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <vector>

class Matrix {
protected:
    std::vector<std::vector<int>> matrix_;
public:
    explicit Matrix(int size);
    Matrix(const Matrix &matrix);
    Matrix(Matrix &&matrix) noexcept;
    virtual ~Matrix() = default;

    void Set(const int row, const int col, const int value) {
        matrix_[row][col] = value;
    }
    void Print() const;

    double operator()(const int i, const int j) const {
        return matrix_[i][j];
    }
};

class SGraph final : public Matrix {
public:
    explicit SGraph(const int size) : Matrix(size) {}
    SGraph(const SGraph &graph) = default;
    ~SGraph() override = default;
    void AddEdge(int v0, int v1);
    void DeleteEdge(int v0, int v1);
    [[nodiscard]] SGraph ShortestPath(int v_from, int v_to) const;
};

#endif //GRAPH_H
