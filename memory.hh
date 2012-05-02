#ifndef MEMORY_HH_
#define MEMORY_HH_

#include <wtl/memory_iseq.hh>
#include <memory>
#include <utility>

namespace wt {
struct delete_ptr {
    template<class P>
    void operator()(P ptr) const { delete ptr; }
};

struct delete_ptr_arr {
    template<class P>
    void operator()(P ptr) const { delete[] ptr; }
};

template<typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args)
{
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}
} // namespace wt

#endif // MEMORY_HH_
