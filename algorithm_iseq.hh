#ifndef ALGORITHM_ISEQ_HH_
#define ALGORITHM_ISEQ_HH_

///////////////////////////////////////////////////////////////////////////////
/// STL extensions
///
/// January 2009
///
/// Matan Nassau <matan.nassau@gmail.com>
///////////////////////////////////////////////////////////////////////////////

#include <algorithm>

namespace wt {

/// Calls the std::adjacent_find() algorithm for an entire sequence, begin to
/// end.
///
/// \param range A range over a container.
///
/// \return An iterator to the first element of the first pair of equal
/// consecutive elements in the range.  If no such pair is found, the function
/// returns last.
template <typename Fwd>
Fwd adjacent_find(input_sequence_range<Fwd> range)
{
    return std::adjacent_find(range.first, range.second);
}

/// Calls the std::adjacent_find() algorithm for an entire sequence, begin to
/// end, with the given binary predicate.
///
/// \param range A range over a container.
///
/// \return An iterator to the first element of the first pair of equal
/// consecutive elements in the range.  If no such pair is found, the function
/// returns last.
template <typename Fwd, typename BinPred>
Fwd adjacent_find(input_sequence_range<Fwd> range, BinPred pred)
{
    return std::adjacent_find(range.first, range.second, pred);
}

template <typename In, typename Op>
Op for_each(input_sequence_range<In> range, Op op)
{
    return std::for_each(range.first, range.second, op);
}

template <typename In, typename V>
In find(input_sequence_range<In> range, const V& val)
{
    return std::find(range.first, range.second, val);
}

template <typename In, typename Pred>
In find_if(input_sequence_range<In> range, Pred op)
{
    return std::find_if(range.first, range.second, op);
}

} // namespace wt

#endif // ALGORITHM_ISEQ_HH_
