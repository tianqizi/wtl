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

template<typename In, typename Out>
Out adjacent_difference(input_sequence_range<In> range, Out res)
{
    return std::adjacent_difference(range.first, range.second, res);
}

template<typename In, typename Out, typename BinOp>
Out adjacent_difference(input_sequence_range<In> range, Out res, BinOp op)
{
    return std::adjacent_difference(range.first, range.second, res, op);
}

template<typename In, typename In2, typename V>
V inner_product(input_sequence_range<In> range, In2 first2, V init)
{
    return std::inner_product(range.first, range.second, first2, init);
}

template<typename In,
         typename In2,
         typename V,
         typename BinOp1,
         typename BinOp2>
V inner_product(input_sequence_range<In> range,
                In2 first2,
                V init,
                BinOp1 op1, BinOp2 op2)
{
    return std::inner_product(range.first, range.second,
                              first2,
                              init,
                              op1, op2);
}

template<typename In, typename Out>
Out partial_sum(input_sequence_range<In> range, Out res)
{
    return std::partial_sum(range.first, range.second, res);
}

template<typename In, typename Out, typename BinOp>
Out partial_sum(input_sequence_range<In> range, Out res, BinOp op)
{
    return std::partial_sum(range.first, range.second, res, op);
}

} // namespace wt

#endif // NUMERIC_ISEQ_HH_
