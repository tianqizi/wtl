#ifndef ASSERT_HH_
#define ASSERT_HH_

///////////////////////////////////////////////////////////////////////////////
/// STL extensions
///
/// January 2009
///
/// Matan Nassau <matan.nassau@gmail.com>
///////////////////////////////////////////////////////////////////////////////

namespace wt {

/// Throw an exception of type X if the given assertion doesn't hold.
///
/// \param assertion Expression that is assumed to be true.  If the expression
/// evaluates to true then nothing happens; otherwise an exception of type X is
/// throw.
template <typename X, typename A>
inline void Assert(A assertion)
{
    if( !assertion ) throw X();
}

}

#endif // ASSERT_HH_
