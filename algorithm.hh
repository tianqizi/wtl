#ifndef WTSTL_ALGORITHM_HH_
#define WTSTL_ALGORITHM_HH_

///////////////////////////////////////////////////////////////////////////////
/// STL extensions
///
/// January 2009
///
/// Matan Nassau <matan.nassau@gmail.com>
///////////////////////////////////////////////////////////////////////////////

#include <wtstl/iseq.hh>
#include <wtstl/algorithm_iseq.hh>

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

}

#endif // WTSTL_ALGORITHM_HH_
