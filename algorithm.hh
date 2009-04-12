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

/// NOTE that none of the algorithms perform a range check;  the iterators
/// given are all assumed to be valid.

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
template<typename In, typename Out, typename Pred>
Out copy_if(In first, In last, Out result, Pred op)
{
    while( first != last ) {
        if( op(*first) ) *result++ = *first;
        ++first;
    }
    return result;
}

/// Copy elements from one container into another until a predicate is
/// satisfied.
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
/// \param op A predicate which elements to be copied must satisfy.  When the
/// predicate is satisfied the copy procedure stops.  The predicate may be a
/// function pointer or a function object.
///
/// \return An iterator pointing to one-past-the-last element of the output
/// container.
template<typename In, typename Out, typename Pred>
Out copy_until(In first, In last, Out res, Pred cond)
{
    while( first != last && !cond(*first) )
        *res++ = first++;
    return res;
}

/// Copy elements from one container into another while a predicate is
/// satisfied.
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
/// \param op A predicate which elements to be copied must satisfy.  When the
/// predicate isn't satisfied the copy procedure stops.  The predicate may be a
/// function pointer or a function object.
///
/// \return An iterator pointing to one-past-the-last element of the output
/// container.
template<typename In, typename Out, typename Pred>
Out copy_while(In first, In last, Out res, Pred cond)
{
    while( first != last && cond(*first) )
        *res++ = first++;
    return res;
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
std::pair<In1,In2> match(In1 first1, In1 last1, In2 first2)
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
std::pair<In1,In2> match(In1 first1, In1 last1, In2 first2, BinPred op)
{
    while( first1 != last1 && !op(*first1, *first2) ) {
        ++first1;
        ++first2;
    }
    return std::make_pair(first1, first2);
}

/// Find the first element in sequence a that doesn't exist in sequence b.
///
/// \param first1 an _input iterator_ pointing to the first element of the
/// first input sequence.
///
/// \param last1 an _input iterator_ pointing to the last element of the first
/// input sequence.
///
/// \param first2 a _forward iterator_ pointing to the first element of the
/// second input sequence.
///
/// \param last2 a _forward iterator_ pointing to the last element of the
/// second input sequence.
///
/// \return An iterator pointing to the first element that doesn't exist in the
/// second sequence if such an element exist, or the end iterator of the first
/// sequence if no such element exists.
template<typename In, typename Fwd>
In find_first_not_of(In first1, In last1, Fwd first2, Fwd last2)
{
    for (; first1 != last1; ++first1) {
        Fwd iter = first2;
        for (; iter != last2 && *first1 != *iter; ++iter);
        if( iter == last2 ) return first1;
    }
    return last1;
}

/// Find the first element in sequence a that doesn't exist in sequence b.
///
/// \param first1 an _input iterator_ pointing to the first element of the
/// first input sequence.
///
/// \param last1 an _input iterator_ pointing to the last element of the first
/// input sequence.
///
/// \param first2 a _forward iterator_ pointing to the first element of the
/// second input sequence.
///
/// \param last2 a _forward iterator_ pointing to the last element of the
/// second input sequence.
///
/// \param op A custom predicate to apply, instead of the default equality
/// operator.
///
/// \return An iterator pointing to the first element that doesn't exist in the
/// second sequence if such an element exist, or the end iterator of the first
/// sequence if no such element exists.
template<typename In, typename Fwd, typename BinPred>
In find_first_not_of(In first1, In last1, Fwd first2, Fwd last2, BinPred op)
{
    for (; first1 != last1; ++first1) {
        Fwd iter = first2;
        for (; iter != last2 && !op(*first1, *iter); ++iter);
        if( iter == last2 ) return first1;
    }
    return last1;
}

/// NULL
class Nothing {
public:
  Nothing() { }

  template<typename T>
    operator T*() const { return 0; } // support implicit-cast to type T*

  template<typename C, typename T>
    operator T C::*() const { return 0; } // implicit-cast to ptr-to-member C::*

private:
  void operator&() const; // do not allow taking address of.
};
const Nothing nil;

}

#endif // WTSTL_ALGORITHM_HH_
