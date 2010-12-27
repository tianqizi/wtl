#ifndef MEMORY_HH_
#define MEMORY_HH_

#include <wtl/memory_iseq.hh>

namespace wt {
struct delete_ptr {
    template<class P>
    void operator()(P ptr) const { delete ptr; }
};

struct delete_ptr_arr {
    template<class P>
    void operator()(P ptr) const { delete[] ptr; }
};
} // namespace wt

#endif // MEMORY_HH_
