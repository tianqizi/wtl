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

}

#endif // ALGORITHM_ISEQ_HH_
