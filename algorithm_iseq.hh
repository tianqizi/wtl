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

template <typename Fwd, typename Fwd2>
Fwd find_first_of(input_sequence_range<Fwd> range,
                  input_sequence_range<Fwd2> range2)
{
    return std::find_first_of(range.first, range.second,
                              range2.first, range2.second);
}

template <typename Fwd, typename Fwd2, typename BinPred>
Fwd find_first_of(input_sequence_range<Fwd> range,
                  input_sequence_range<Fwd2> range2,
                  BinPred op)
{
    return std::find_first_of(range.first, range.second,
                              range2.first, range2.second,
                              op);
}

template <typename In, typename V>
typename std::iterator_traits<In>::difference_type
count(input_sequence_range<In> range, const V& val)
{
    return std::count(range.first, range.second, val);
}

template <typename In, typename V, typename BinPred>
typename std::iterator_traits<In>::difference_type
count_if(input_sequence_range<In> range, const V& val, BinPred op)
{
    return std::count(range.first, range.second, val, pred);
}

template <typename In, typename In2>
bool equal(input_sequence_range<In> range, input_sequence_range<In2> range2)
{
    return std::equal(range.first, range.second, range2.first, range2.second);
}

template <typename In, typename In2, typename BinPred>
bool equal(input_sequence_range<In> range,
           input_sequence_range<In2> range2,
           BinPred op)
{
    return std::equal(range.first, range.second,
                      range2.first, range2.second,
                      op);
}

template <typename In, typename In2>
std::pair<In,In2> mismatch(input_sequence_range<In> range,
                           input_sequence_range<In2> range2)
{
    return std::mismatch(range.first, range.second,
                         range2.first, range2.second);
}

template <typename In, typename In2, typename BinPred>
std::pair<In,In2> mismatch(input_sequence_range<In> range,
                           input_sequence_range<In2> range2,
                           BinPred op)
{
    return std::mismatch(range.first, range.second,
                         range2.first, range2.second,
                         op);
}

template <typename Fwd, typename Fwd2>
Fwd search(input_sequence_range<Fwd> range, input_sequence_range<Fwd2> range2)
{
    return std::search(range.first, range.second, range2.first, range2.second);
}

template <typename Fwd, typename Fwd2, typename BinPred>
Fwd search(input_sequence_range<Fwd> range,
           input_sequence_range<Fwd2> range2,
           BinPred op)
{
    return std::search(range.first, range.second,
                       range2.first, range2.second,
                       op);
}

template <typename Fwd, typename Fwd2>
Fwd find_end(input_sequence_range<Fwd> range,
             input_sequence_range<Fwd2> range2)
{
    return std::find_end(range.first, range.second,
                         range2.first, range2.second);
}

template <typename Fwd, typename Fwd2, typename BinPred>
Fwd find_end(input_sequence_range<Fwd> range,
             input_sequence_range<Fwd2> range2,
             BinPred op)
{
    return std::find_end(range.first, range.second,
                         range2.first, range2.second,
                         op);
}

template <typename Fwd, typename Size, typename V>
Fwd search_n(input_sequence_range<Fwd> range, Size n, const V& val)
{
    return std::search_n(range.first, range.second, n, val);
}

template <typename Fwd, typename Size, typename V, typename BinPred>
Fwd search_n(input_sequence_range<Fwd> range, Size n, const V& val, BinPred op)
{
    return std::search(range.first, range.second, n, val, op);
}

template <typename In, typename Out>
Out copy(input_sequence_range<In> range, Out result)
{
    return std::copy(range.first, range.second, result);
}

template <typename Bi, typename Bi2>
Out copy_backward(input_sequence_range<Bi> range, Bi2 result)
{
    return std::copy_backward(range.first, range.second, result);
}

template <typename In, typename Out, typename Op>
Out transform(input_sequence_range<In> range, Out res, Op op)
{
    return std::transform(range.first, range.second, res, op);
}

template <typename In, typename In2, typename Out, typename Op>
Out transform(input_sequence_range<In> range,
              input_sequence_range<In2> range2,
              Out res,
              Op op)
{
    return std::transform(range.first, range.second,
                          range2.first, range2.second,
                          res, op);
}

template <typename Fwd>
Fwd unique(input_sequence_range<Fwd> range)
{
    return std::unique(range.first, range.second);
}

template <typename Fwd, typename BinPred>
Fwd unique(input_sequence_range<Fwd> range, BinPred op)
{
    return std::unique(range.first, range.second, op);
}

template <typename Fwd, typename Out>
Out unique_copy(input_sequence_range<Fwd> range, Out res)
{
    return std::unique_copy(range.first, range.second, res);
}

template <typename Fwd, typename Out, typename BinPred>
Out unique_copy(input_sequence_range<Fwd> range, Out res, BinPred op)
{
    return std::unique_copy(range.first, range.second, res, op);
}

} // namespace wt

#endif // ALGORITHM_ISEQ_HH_
