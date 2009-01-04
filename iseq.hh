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

namespace wt {

/// Pair of _input iterators_ expressing a range of an input sequence.
///
/// \see iseq()
template<typename In>
struct input_sequence_range : public std::pair<In,In> {
    input_sequence_range(In first, In last) : std::pair(first, last) { }
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

}

#endif // ISEQ_HH_
