#ifndef STOCK_H
#define STOCK_H

#include <map>
#include <set>

class Stock {
private:
    struct Box { int w; int v; };

    std::map<int, Box>           boxes_;
    std::map<int, std::set<int>> byW_;
    std::map<int, std::set<int>> byV_;
    int nextSerial_;

    void removeBox_(int serial);

public:
    Stock();

    void Add(int w, int v);
    int  GetByW(int min_w);
    int  GetByV(int min_v);

    int  Size()  const;
    bool Empty() const;
    void PrintState() const;
};

#endif