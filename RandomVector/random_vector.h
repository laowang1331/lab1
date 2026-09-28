#ifndef RANDOM_VECTOR_H
#define RANDOM_VECTOR_H

#include <vector>
#include <iostream>

class RandomVector {
public:
    RandomVector(int size, double max_val = 1);
    double mean() const;
    double max() const;
    double min() const;
    void print() const;
    void printHistogram(int bins) const;

private:
    std::vector<double> data;
};

#endif
