#ifndef WTSTL_ALGORITHM_HH_
#define WTSTL_ALGORITHM_HH_

///////////////////////////////////////////////////////////////////////////////
/// STL extensions
///
/// January 2009
///
/// Matan Nassau <matan.nassau@gmail.com>
///////////////////////////////////////////////////////////////////////////////

#include <wtl/algorithm_iseq.hh>

namespace wt {

/// Copy n elements from one container into another.
///
/// \param first An _input iterator_ pointing to the first element of the input
/// sequence.
///
/// \param n The count of elements that should be copied.
///
/// \param result An _output iterator_ pointing to the container into which the
/// elements should be copied.
///
/// \return An iterator pointing to one-past-the-last element of the output
/// container.
///
/// Note that no range check is made;  the iterators given are all assumed to
/// be valid.
template<typename In, typename Size, typename Out>
Out copy_n(In first, Size n, Out result)
{
    while( n-- > 0 ) *result++ = *first++;
    return result;
}

/// Copy elements which satisfy a predicate from one container into another.
///
/// \param first An _input iterator_ pointing to the first element of the input
/// sequence.
///
/// \param last An _input iterator_ pointing to the last element of the input
/// sequence.
///
/// \param result An _output iterator_ pointing to the container into which the
/// elements should be copied.
///
/// \param op A predicate which elements to be copied must satisfy.  The
/// predicate may be a function pointer or a function object.
///
/// \return An iterator pointing to one-past-the-last element of the output
/// container.
///
/// Note that no range check is made;  the iterators given are all assumed to
/// be valid.
template<typename In, typename Out, typename Pred>
Out copy_if(In first, In last, Out result, Pred op)
{
    while( first != last ) {
        if( op(*first) ) *result++ = *first;
        ++first;
    }
    return result;
}

/// Find the first pair of elements that compare equal.  The match() algorithm
/// is complementary to the std::mismatch() algorithm.
///
/// \param first1 an _input iterator_ pointing to the first element of the
/// first input sequence.
///
/// \param last1 an _input iterator_ pointing to the last element of the first
/// input sequence.
///
/// \param first2 an _input iterator_ pointing to the first element of the
/// second input sequence.
///
/// \return A pair of iterators pointing to the two elements that are equal.
/// The first iterator points to an element in the first sequence, and the
/// second iterator points to an element in the second sequence.
template <typename In1, typename In2>
std::pair<In,In2> match(In1 first1, In1 last1, In2 first2)
{
    while( first1 != last1 && !(*first1 == *first2) ) {
        ++first1;
        ++first2;
    }
    return std::make_pair(first1, first2);
}

/// Find the first pair of elements that compare equal.  The match() algorithm
/// is complementary to the std::mismatch() algorithm.
///
/// \param first1 an _input iterator_ pointing to the first element of the
/// first input sequence.
///
/// \param last1 an _input iterator_ pointing to the last element of the first
/// input sequence.
///
/// \param first2 an _input iterator_ pointing to the first element of the
/// second input sequence.
///
/// \param op A custom predicate to apply, instead of the default negated
/// equality operator.
///
/// \return A pair of iterators pointing to the two elements that are equal.
/// The first iterator points to an element in the first sequence, and the
/// second iterator points to an element in the second sequence.
template <typename In1, typename In2, typename BinPred>
std::pair<In,In2> match(In1 firs1t, In1 last1, In2 first2, BinPred op)
{
    while( first1 != last1 && !op(*first1, *first2) ) {
        ++first1;
        ++first2;
    }
    return std::make_pair(first1, first2);
}

}

#endif // WTSTL_ALGORITHM_HH_
