#include <vector>
#include <chrono>


class SortingAlgorithm {
public:
    virtual void sort(std::vector<int>& arr) = 0;
    virtual ~SortingAlgorithm() {}
};


class BubbleSort : public SortingAlgorithm {
public:
    void sort(std::vector<int>& arr) {
        int n = arr.size();
        bool swapped = true;
        while (swapped) {
            swapped = false;
            for (int i = 1; i < n; i++) {
                if (arr[i - 1] > arr[i]) {
                    std::swap(arr[i - 1], arr[i]);
                    swapped = true;
                }
            }
            n--;
        }
    }
};

class TimeDecorator : public SortingAlgorithm {
public:
    TimeDecorator(SortingAlgorithm* algorithm) : m_algorithm(algorithm) {}
    void sort(std::vector<int>& arr) {
        auto start = std::chrono::high_resolution_clock::now();
        m_algorithm->sort(arr);
        auto end = std::chrono::high_resolution_clock::now();
        m_execution_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    }
    long long get_execution_time() const { return m_execution_time; }
private:
    SortingAlgorithm* m_algorithm;
    long long m_execution_time;
};

class ComplexityVisitor {
public:
    void visit(BubbleSort& algorithm) {
        m_time_complexity = "O(n^2)";
        m_space_complexity = "O(1)";
    }
    std::string get_time_complexity() const { return m_time_complexity; }
    std::string get_space_complexity() const { return m_space_complexity; }
private:
    std::string m_time_complexity;
    std::string m_space_complexity;
};

class AlgorithmBuilder {
public:
    static SortingAlgorithm* build(std::string algorithm_name) {
        if (algorithm_name == "BubbleSort") {
            return new BubbleSort();
        }
        return nullptr;
    }
};


class SortApp {
public:
    SortApp() {
        m_algorithms.push_back(AlgorithmBuilder::build("BubbleSort"));
    }
    ~SortApp() {
        for (auto algorithm : m_algorithms) {
            delete algorithm;
        }
    }
    void run() {
        std::vector<int> arr = { 5, 3, 7, 1, 8, 2 };
        for (auto algorithm : m_algorithms) {
            TimeDecorator time_decorator(algorithm);
            time_decorator.sort(arr);
            long long execution_time = time_decorator.get_execution_time();
            ComplexityVisitor complexity_visitor;
            algorithm->accept(complexity_visitor);
            std::string time_complexity = complexity_visitor.get_time_complexity();
            std::string space_complexity = complexity_visitor.get_space_complexity();
        }
    }
private:
    std::vector<SortingAlgorithm*> m_algorithms;
};
