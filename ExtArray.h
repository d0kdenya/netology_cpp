#pragma once
#include <vector>
#include <initializer_list>
#include <algorithm>
#include <numeric>
#include <typeinfo>
#include <type_traits>
#include <stdexcept>

template<typename T>
class ExtArray {
private:
    std::vector<T> data_;
public:
    ExtArray(std::initializer_list<T> l) : data_(l) {}
    explicit ExtArray(std::size_t n)      : data_(n) {}

    T& operator[](std::size_t idx)              { return data_.at(idx); }
    const T& operator[](std::size_t idx) const  { return data_.at(idx); }

    std::size_t size()  const { return data_.size(); }

    double mean() const
    {
        if (data_.empty()) return 0.0;
        long double sum = std::accumulate(data_.begin(), data_.end(), 0.0L);
        return static_cast<double>(sum / data_.size());
    }

    double mean(std::size_t first, std::size_t last) const
    {
        if (first >= last || last > data_.size())
            throw std::invalid_argument("invalid range for mean()");
        long double sum =
            std::accumulate(data_.begin() + first, data_.begin() + last, 0.0L);
        return static_cast<double>(sum / (last - first));
    }

    std::size_t checkSum() const
    {
        if constexpr (!(std::is_same_v<T, bool> || std::is_same_v<T, int>))
            throw std::bad_typeid();

        std::size_t ones = 0;
        for (const auto& v : data_) {
            if constexpr (std::is_same_v<T, int>) {
                if (v != 0 && v != 1)
                    throw std::logic_error("int array contains not 0/1");
                ones += static_cast<std::size_t>(v);
            } else {
                ones += v ? 1u : 0u;
            }
        }
        return ones;
    }

    double median() const
    {
        if (data_.empty()) return 0.0;
        std::vector<T> tmp = data_;
        std::sort(tmp.begin(), tmp.end());
        std::size_t n = tmp.size();
        if (n % 2) return static_cast<double>(tmp[n/2]);
        return static_cast<double>(tmp[n/2-1] + tmp[n/2]) / 2.0;
    }

    std::pair<T,int> mode() const
    {
        if (data_.empty()) return {0,0};
        std::vector<T> tmp = data_;
        std::sort(tmp.begin(), tmp.end());
        T bestVal = tmp[0];
        int bestCnt = 1, curCnt = 1;
        for (std::size_t i = 1; i < tmp.size(); ++i) {
            curCnt = (tmp[i] == tmp[i-1]) ? curCnt + 1 : 1;
            if (curCnt > bestCnt) { bestCnt = curCnt; bestVal = tmp[i]; }
        }
        return {bestVal, bestCnt};
    }
};