#ifndef ISEQ_HH_
#define ISEQ_HH_

///////////////////////////////////////////////////////////////////////////////
/// STL extensions
///
/// January 2009
///
/// Matan Nassau <matan.nassau@gmail.com>
///////////////////////////////////////////////////////////////////////////////

#include <utility>
#include <iterator>

namespace wt {

/// Pair of _input iterators_ expressing a range of an input sequence.
///
/// \see iseq()
template<typename In>
struct input_sequence_range : public std::pair<In,In> {
    input_sequence_range(In first, In last) : std::pair<In,In>(first, last) { }
};

/// Helper function to generate an input_sequence_range which expresses the
/// range of a given input sequence, from begin to end.
///
/// This function can be used with standard aglrothims extensions as a
/// shorthand for invoking algorithms in the common manner, over an entire
/// sequence.  For instance, instead of invoking
///
///  iter pos = find(cont.begin(), cont.end(), 42);
///
/// you may run
///
///  iter pos = find(iseq(cont), 42);
///
/// where cont is some container.
///
/// \param c A container.  The container must support the begin() and end()
/// function, each returning an interator pointing into the container.
///
/// \return A range over the given container, from begin to end.
template<typename C>
input_sequence_range<typename C::iterator> iseq(C& c)
{
    return input_sequence_range<typename C::iterator>(c.begin(), c.end());
}

/// Helper function to generate an input_sequence_range which expresses the
/// range of a given primitive array, from begin to end.
///
/// This function can be used with standard aglrothims extensions as a
/// shorthand for invoking algorithms in the common manner, over an entire
/// array.  For instance, instead of invoking
///
///  iter pos = find(arr, arr + 10, 42);
///
/// you may run
///
///  iter pos = find(iseq(arr, 10), 42);
///
/// where arr is some primitive array.
///
/// You must pass the size of the array, as it would otherwise be expensive for
/// the function to find it out by itself.
///
/// \param a A primitive array.
///
/// \param n The number of elements in the array.
///
/// \return A range over the given array, from begin to end.
template<typename Arr, typename Size>
input_sequence_range<Arr*> iseq(Arr* a, Size n)
{
    return input_sequence_range<Arr*>(a, a + n);
}

} // namespace wt

#endif // ISEQ_HH_
