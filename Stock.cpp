#include "Stock.h"
#include <iostream>

Stock::Stock() : nextSerial_(0) {}

void Stock::Add(int w, int v) {
    int serial = nextSerial_++;
    boxes_[serial] = Box{ w, v };
    byW_[w].insert(serial);
    byV_[v].insert(serial);
}

int Stock::GetByW(int min_w) {
    auto it = byW_.lower_bound(min_w);
    if (it == byW_.end()) return -1;
    int serial = *it->second.rbegin();
    removeBox_(serial);
    return serial;
}

int Stock::GetByV(int min_v) {
    auto it = byV_.lower_bound(min_v);
    if (it == byV_.end()) return -1;
    int serial = *it->second.rbegin();
    removeBox_(serial);
    return serial;
}

int  Stock::Size()  const { return static_cast<int>(boxes_.size()); }
bool Stock::Empty() const { return boxes_.empty(); }

void Stock::removeBox_(int serial) {
    auto bit = boxes_.find(serial);
    if (bit == boxes_.end()) return;
    Box b = bit->second;

    auto wit = byW_.find(b.w);
    if (wit != byW_.end()) {
        wit->second.erase(serial);
        if (wit->second.empty()) byW_.erase(wit);
    }
    auto vit = byV_.find(b.v);
    if (vit != byV_.end()) {
        vit->second.erase(serial);
        if (vit->second.empty()) byV_.erase(vit);
    }
    boxes_.erase(bit);
}

void Stock::PrintState() const {
    std::cout << "Склад (" << boxes_.size() << " коробок):\n";
    for (const auto& kv : boxes_)
        std::cout << "  #" << kv.first
        << ": w=" << kv.second.w
        << ", v=" << kv.second.v << "\n";
}