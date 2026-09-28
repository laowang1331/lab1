#include "random_vector.h"
#include <cstdlib>
#include <ctime>

RandomVector::RandomVector(int size, double max_val) {
    data.resize(size);
    for (int i = 0; i < size; ++i) {
        data[i] = (double)rand() / RAND_MAX * max_val;
    }
}

double RandomVector::mean() const {
    if (data.empty()) return 0.0;
    double sum = 0.0;
    for (size_t i = 0; i < data.size(); ++i) {
        sum += data[i];
    }
    return sum / data.size();
}

double RandomVector::max() const {
    if (data.empty()) return 0.0;
    double m = data[0];
    for (size_t i = 1; i < data.size(); ++i) {
        if (data[i] > m) m = data[i];
    }
    return m;
}

double RandomVector::min() const {
    if (data.empty()) return 0.0;
    double m = data[0];
    for (size_t i = 1; i < data.size(); ++i) {
        if (data[i] < m) m = data[i];
    }
    return m;
}

void RandomVector::print() const {
    for (size_t i = 0; i < data.size(); ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

void RandomVector::printHistogram(int bins) const {
    if (data.empty() || bins <= 0) return;

    double min_val = min();
    double max_val = max();

    if (min_val == max_val) {
        std::cout << "[" << min_val << "] : " << data.size() << std::endl;
        return;
    }

    std::vector<int> counts(bins, 0);
    double width = (max_val - min_val) / bins;

    for (size_t i = 0; i < data.size(); ++i) {
        int index = (int)((data[i] - min_val) / width);
        if (index >= bins) index = bins - 1;
        if (index < 0) index = 0;
        counts[index]++;
    }

    for (int b = 0; b < bins; ++b) {
        double low = min_val + b * width;
        double high = min_val + (b + 1) * width;
        std::cout << "[" << low << ", " << high << ") : ";
        for (int c = 0; c < counts[b]; ++c) {
            std::cout << "*";
        }
        std::cout << " (" << counts[b] << ")" << std::endl;
    }
}
