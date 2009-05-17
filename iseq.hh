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
/// range of a given const input sequence, from begin to end.
///
/// This function can be used with standard aglrothims extensions as a
/// shorthand for invoking algorithms in the common manner, over an entire
/// sequence.  For instance, instead of invoking
///
///  iter pos = find(cont.begin(), cont.end(), 42);
///
/// you can run
///
///  iter pos = find(iseq(cont), 42);
///
/// where cont is some container.  Because the returned range object holds
/// const_iterators you can use this iseq() overload in an expression that
/// takes constant values, such as temporals:
///
///  return find(iseq(cont), 1337);
///
/// \param c A container.  The container must support the begin() and end()
/// function, each returning an interator pointing into the container.
///
/// \return A range over the given container, from begin to end.
template<typename C>
input_sequence_range<typename C::const_iterator> iseq(const C& c)
{
    return input_sequence_range<typename C::const_iterator>(c.begin(), c.end());
}

/// Helper function to generate an input_sequence_range which expresses the
/// range of a given input sequence, from begin to end.
///
/// This function can be used with standard aglrothims extensions as a
/// shorthand for invoking algorithms in the common manner, over an entire
/// sequence.  For instance, instead of invoking
///
///  iter pos = find(cont.begin(), cont.end(), 42);
///
/// you can run
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
/// you can run
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
template<typename Arr>
input_sequence_range<Arr*> iseq(Arr* a, typename std::iterator_traits<Arr*>::difference_type n)
{
    return input_sequence_range<Arr*>(a, a + n);
}

/// Helper function to generate an input_sequence_range which expresses the
/// range of a given stream, from begin to end.
///
/// This function can be used with standard aglrothims extensions as a
/// shorthand for invoking algorithms in the common manner, over an entire
/// stream using a stream iterator.  For instance, instead of invoking
///
///  iter pos = find(istream_iterator<int>(cin), istream_iterator<int>(), 42);
///
/// you can run
///
///  iter pos = find(iseq<int>(cin), 42);
///
/// where cin is some input stream.
///
/// \param s An input stream.
///
/// \param T The type of values expected from the input stream s.
///
/// \return A range over the given stream, from begin to end.
template<typename T, typename Ch, typename Tr>
input_sequence_range<std::istream_iterator<T> > iseq(std::basic_istream<Ch,Tr>& s)
{
    typedef std::istream_iterator<T> siter;
    return input_sequence_range<siter>(siter(s), siter());
}

/// Helper function to generate an input_sequence_range which expresses the
/// range of two given iterators.
///
/// This function can be used with standard aglrothims extensions,
/// complementing the other iseq() templates.  By itself it may seem like not
/// much help comparing to invoking algorithms in the standard manner, with two
/// iterators.  Its intent, however, is to prevent an explosion of verloads for
/// new algorithms.  You can write a single version for your next algorithm
/// that takes an input_sequence_range as its range argument, as opposed to
/// writing one overload with two iterator arguments and another with an
/// input_sequence_range argument.
///
/// To use, instead of calling
///
///  iter pos = find(cont.begin(), cont.end(), 42);
///
/// call
///
///  iter pos = find(iseq(cont.begin(), cont.end()), 42);
///
/// where cont is some container.
///
/// \param c A container.  The container must support the begin() and end()
/// function, each returning an interator pointing into the container.
///
/// \return A range over the given container, from begin to end.
template<typename Iter>
input_sequence_range<Iter> iseq(Iter first, Iter last)
{
    return input_sequence_range<Iter>(first, last);
}

} // namespace wt

#endif // ISEQ_HH_
