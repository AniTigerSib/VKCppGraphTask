//
// Created by Micha on 17.03.2025.
//

#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <stack>
#include <vector>

class Matrix {
protected:
    std::vector<std::vector<int>> matrix_;
public:
    explicit Matrix(int size);
    Matrix(const Matrix &matrix);
    Matrix(Matrix &&matrix) noexcept;
    virtual ~Matrix() = default;

    void Set(const int row, const int col, const int value) noexcept {
        matrix_[row][col] = value;
    }
    void Print() const;

    double operator()(const int i, const int j) const noexcept {
        return matrix_[i][j];
    }
};

class SGraph final : public Matrix {
public:
    explicit SGraph(const int size) : Matrix(size) {}
    SGraph(const SGraph &graph) = default;
    SGraph(SGraph &&graph) noexcept = default;
    ~SGraph() override = default;
    void AddEdge(int v0, int v1) noexcept;
    void DeleteEdge(int v0, int v1) noexcept;
    [[nodiscard]] std::stack<int> ShortestPath(int v_from, int v_to) const;
};

class SGraphException final : public std::exception {
public:
    explicit SGraphException(const char *msg = "SGraph exception") : msg_(msg) {}
    [[nodiscard]] char const *what() const noexcept {
        return msg_;
    }
private:
    char const *msg_;
};

#endif //GRAPH_H
