#ifndef WTSTL_NUMERIC_HH_
#define WTSTL_NUMERIC_HH_

///////////////////////////////////////////////////////////////////////////////
/// STL extensions
///
/// January 2009
///
/// Matan Nassau <matan.nassau@gmail.com>
///////////////////////////////////////////////////////////////////////////////

#include <wtstl/iseq.hh>
#include <numeric>

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

}

#endif // WTSTL_NUMERIC_HH_
