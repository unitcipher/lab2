#ifndef ODD_EVEN_SEPARATOR_H
#define ODD_EVEN_SEPARATOR_H

#include <vector>

class OddEvenSeparator {
private:
    std::vector<int> numbers;

public:
    void add_number(int n);
    void even() const;
    void odd()  const;
};

#endif