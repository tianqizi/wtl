#ifndef NUMERIC_ISEQ_HH_
#define NUMERIC_ISEQ_HH_

///////////////////////////////////////////////////////////////////////////////
/// STL extensions
///
/// January 2009
///
/// Matan Nassau <matan.nassau@gmail.com>
///////////////////////////////////////////////////////////////////////////////

#include <wtstl/iseq.hh>

namespace wt {

/// Sum elements in a container.
///
/// \param range A range of elements to accumulate.
///
/// \param init The initial value from which accumulation begins.
///
/// \return The sum of all elements.
///
/// Note that no range check is made;  the iterators given are all assumed to
/// be valid.
template<typename In, typename V>
V accumulate(input_sequence_range<In> range, V init)
{
    return std::accumulate(range.first, range.second, init);
}

/// Accumulate elements in a container using a predicate for consecutive
/// operation to apply.
///
/// \param range A range of elements to accumulate.
///
/// \param init The initial value from which accumulation begins.
///
/// \param op The operation to use as the accumulation operation.
///
/// \return The result of accumulating of all elements.
///
/// Note that no range check is made;  the iterators given are all assumed to
/// be valid.
template<typename In, typename V, typename BinOp>
V accumulate(input_sequence_range<In> range, V init, BinOp op)
{
    return std::accumulate(range.first, range.second, init, op);
}

}

#endif // NUMERIC_ISEQ_HH_
