#ifndef MEMORY_ISEQ_HH_
#define MEMORY_ISEQ_HH_

#include <memory>
#include <wtl/iseq.hh>

namespace wt {

template <typename In, typename Fwd>
Fwd uninitialized_copy(input_sequence_range<In> range, Fwd res)
{
    return std::uninitialized_copy(range.first, range.second, res);
}

template <typename Fwd, typename V>
void uninitialized_fill(input_sequence_range<Fwd> range, V val)
{
    std::uninitialized_copy(range.first, range.second, res);
}

} // namespace wt

#endif // MEMORY_ISEQ_HH_
