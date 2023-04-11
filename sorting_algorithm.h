#ifndef SORTING_ALGORITHM_H
#define SORTING_ALGORITHM_H

#include <vector>

class SortingAlgorithm {
public:
    virtual void sort(std::vector<int>& arr) = 0;
    virtual ~SortingAlgorithm() {}
};

#endif // SORTING_ALGORITHM_H
