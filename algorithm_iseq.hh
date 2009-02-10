#ifndef ALGORITHM_ISEQ_HH_
#define ALGORITHM_ISEQ_HH_

///////////////////////////////////////////////////////////////////////////////
/// STL extensions
///
/// iseq algorithms are wrappers for the standard algorithms that make calling
/// the algorithms slightly easier.  These wrappers take a single parameter,
/// called an "iseq" (for "input sequence"), instead of the usual two iterators
/// that represent the range the algorithm will act upon.  The iseq expresses
/// the entire range from begin to end of a sequence.  Thus,
///
/// algorithm(iseq(c)) == algorithm(c.begin(), c.end())
///
/// The iseq() function is a helper for creating an object of the class
/// input_sequence_range<C>, which holds the range begin-to-end of the given
/// container.
///
/// January 2009
///
/// Matan Nassau <matan.nassau@gmail.com>
///////////////////////////////////////////////////////////////////////////////

#include <wtl/iseq.hh>
#include <algorithm>

namespace wt {

template <typename Fwd>
Fwd adjacent_find(input_sequence_range<Fwd> range)
{
    return std::adjacent_find(range.first, range.second);
}

template <typename Fwd, typename BinPred>
Fwd adjacent_find(input_sequence_range<Fwd> range, BinPred op)
{
    return std::adjacent_find(range.first, range.second, op);
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
    return std::count(range.first, range.second, val, op);
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
Bi2 copy_backward(input_sequence_range<Bi> range, Bi2 result)
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

template <typename Fwd, typename V>
void replace(input_sequence_range<Fwd> range, const V& val, const V& new_val)
{
    std::replace(range.first, range.second, val, new_val);
}

template <typename Fwd, typename Pred, typename V>
void replace_if(input_sequence_range<Fwd> range, Pred op, const V& new_val)
{
    std::replace_if(range.first, range.second, op, new_val);
}

template <typename Fwd, typename Out, typename V>
void replace_copy(input_sequence_range<Fwd> range,
                  Out res,
                  const V& val, const V& new_val)
{
    std::replace_copy(range.first, range.second, res, val, new_val);
}

template <typename Fwd, typename Out, typename Pred, typename V>
void replace_copy_if(input_sequence_range<Fwd> range,
                Out res,
                Pred op, const V& new_val)
{
    std::replace_copy_if(range.first, range.second, res, op, new_val);
}

template <typename Fwd, typename V>
Fwd remove(input_sequence_range<Fwd> range, const V& val)
{
    return std::remove(range.first, range.second, val);
}

template <typename Fwd, typename Pred>
Fwd remove_if(input_sequence_range<Fwd> range, Pred op)
{
    return std::remove_if(range.first, range.second, op);
}

template <typename In, typename Out, typename V>
Out remove_copy(input_sequence_range<In> range, Out res, const V& val)
{
    return std::remove_copy(range.first, range.second, res, val);
}

template <typename In, typename Out, typename Pred>
Out remove_copy_if(input_sequence_range<In> range, Out res, Pred op)
{
    return std::remove_copy_if(range.first, range.second, res, op);
}

template <typename Fwd, typename V>
void fill(input_sequence_range<Fwd> range, const V& val)
{
    std::fill(range.first, range.second, val);
}

template <typename Fwd, typename Gen>
void generate(input_sequence_range<Fwd> range, Gen g)
{
    std::generate(range.first, range.second, g);
}

template <typename Bi>
void reverse(input_sequence_range<Bi> range)
{
    std::reverse(range.first, range.second);
}

template <typename Bi, typename Out>
Out reverse_copy(input_sequence_range<Bi> range, Out res)
{
    return std::reverse_copy(range.first, range.second, res);
}

template <typename Fwd>
void rotate(input_sequence_range<Fwd> range, Fwd middle)
{
    std::rotate(range.first, middle, range.second);
}

template <typename Fwd, typename Out>
Out rotate_copy(input_sequence_range<Fwd> range, Fwd middle, Out res)
{
    return std::rotate_copy(range.first, middle, range.second, res);
}

template <typename Ran>
void random_shuffle(input_sequence_range<Ran> range)
{
    std::random_shuffle(range.first, range.second);
}

template <typename Ran, typename Gen>
void random_shuffle(input_sequence_range<Ran> range, Gen& g)
{
    std::random_shuffle(range.first, range.second, g);
}

template <typename Fwd, typename Fwd2>
Fwd2 swap_ranges(input_sequence_range<Fwd> range, Fwd2 first2)
{
    return std::swap_ranges(range.first, range.second, first2);
}

template <typename Ran>
void sort(input_sequence_range<Ran> range)
{
    std::sort(range.first, range.second);
}

template <typename Ran, typename Cmp>
void sort(input_sequence_range<Ran> range, Cmp c)
{
    std::sort(range.first, range.second, c);
}

template <typename Ran>
void stable_sort(input_sequence_range<Ran> range)
{
    std::sort(range.first, range.second);
}

template <typename Ran, typename Cmp>
void stable_sort(input_sequence_range<Ran> range, Cmp c)
{
    std::sort(range.first, range.second, c);
}

template <typename Ran>
void partial_sort(input_sequence_range<Ran> range, Ran middle)
{
    std::partial_sort(range.first, middle, range.second);
}

template <typename Ran, typename Cmp>
void partial_sort(input_sequence_range<Ran> range, Ran middle, Cmp c)
{
    std::partial_sort(range.first, middle, range.second, c);
}

template <typename In, typename Ran>
Ran partial_sort_copy(input_sequence_range<In> range,
                      input_sequence_range<Ran> range2)
{
    return std::partial_sort(range.first, range.second,
                             range2.first, range2.second);
}

template <typename In, typename Ran, typename Cmp>
Ran partial_sort_copy(input_sequence_range<In> range,
                      input_sequence_range<Ran> range2,
                      Cmp c)
{
    return std::partial_sort(range.first, range.second,
                             range2.first, range2.second,
                             c);
}

template <typename Ran>
void nth_element(input_sequence_range<Ran> range, Ran nth)
{
    std::nth_element(range.first, nth, range.second);
}

template <typename Ran, typename Cmp>
void nth_element(input_sequence_range<Ran> range, Ran nth, Cmp c)
{
    std::nth_element(range.first, nth, range.second, c);
}

template <typename Ran, typename V>
bool binary_search(input_sequence_range<Ran> range, const V& val)
{
    return std::binary_search(range.first, range.second, val);
}

template <typename Ran, typename V, typename Cmp>
bool binary_search(input_sequence_range<Ran> range, const V& val, Cmp c)
{
    return std::binary_search(range.first, range.second, val, c);
}

template <typename Fwd, typename V>
Fwd lower_bound(input_sequence_range<Fwd> range, const V& val)
{
    return std::lower_bound(range.first, range.second, val);
}

template <typename Fwd, typename V, typename Cmp>
Fwd lower_bound(input_sequence_range<Fwd> range, const V& val, Cmp c)
{
    return std::lower_bound(range.first, range.second, val, c);
}

template <typename Fwd, typename V>
Fwd upper_bound(input_sequence_range<Fwd> range, const V& val)
{
    return std::upper_bound(range.first, range.second, val);
}

template <typename Fwd, typename V, typename Cmp>
Fwd upper_bound(input_sequence_range<Fwd> range, const V& val, Cmp c)
{
    return std::upper_bound(range.first, range.second, val, c);
}

template <typename Fwd, typename V>
std::pair<Fwd,Fwd> equal_range(input_sequence_range<Fwd> range, const V& val)
{
    return std::equal_range(range.first, range.second, val);
}

template <typename Fwd, typename V, typename Cmp>
std::pair<Fwd,Fwd> equal_range(input_sequence_range<Fwd> range,
                               const V& val, Cmp c)
{
    return std::equal_range(range.first, range.second, val, c);
}

template <typename In, typename In2, typename Out>
Out merge(input_sequence_range<In> range,
          input_sequence_range<In2> range2,
          Out res)
{
    return std::merge(range.first, range.second,
                      range2.first, range2.second,
                      res);
}

template <typename In, typename In2, typename Out, typename Cmp>
Out merge(input_sequence_range<In> range,
          input_sequence_range<In2> range2,
          Out res,
          Cmp c)
{
    return std::merge(range.first, range.second,
                      range2.first, range2.second,
                      res, c);
}

template <typename Bi>
void inplace_merge(input_sequence_range<Bi> range, Bi middle)
{
    std::inplace_merge(range.first, middle, range.second);
}

template <typename Bi, typename Cmp>
void inplace_merge(input_sequence_range<Bi> range, Bi middle, Cmp c)
{
    std::inplace_merge(range.first, middle, range.second, c);
}

template <typename Bi, typename Pred>
Bi partition(input_sequence_range<Bi> range, Pred op)
{
    return std::partition(range.first, range.second, op);
}

template <typename Bi, typename Pred>
Bi stable_partition(input_sequence_range<Bi> range, Pred op)
{
    return std::stable_partition(range.first, range.second, op);
}

template <typename In, typename In2>
bool includes(input_sequence_range<In> range, input_sequence_range<In2> range2)
{
    return std::includes(range.first, range.second,
                         range2.first, range2.second);
}

template <typename In, typename In2, typename Cmp>
bool includes(input_sequence_range<In> range,
              input_sequence_range<In2> range2,
              Cmp c)
{
    return std::includes(range.first, range.second,
                         range2.first, range2.second,
                         c);
}

template <typename In, typename In2, typename Out>
Out set_union(input_sequence_range<In> range,
              input_sequence_range<In2> range2,
              Out res)
{
    return std::set_union(range.first, range.second,
                          range.first, range.second,
                          res);
}

template <typename In, typename In2, typename Out, typename Cmp>
Out set_union(input_sequence_range<In> range,
              input_sequence_range<In2> range2,
              Out res, Cmp c)
{
    return std::set_union(range.first, range.second,
                          range.first, range.second,
                          res, c);
}

template <typename In, typename In2, typename Out>
Out set_intersection(input_sequence_range<In> range,
                     input_sequence_range<In2> range2,
                     Out res)
{
    return std::set_intersection(range.first, range.second,
                                 range.first, range.second,
                                 res);
}

template <typename In, typename In2, typename Out, typename Cmp>
Out set_intersection(input_sequence_range<In> range,
                     input_sequence_range<In2> range2,
                     Out res, Cmp c)
{
    return std::set_intersection(range.first, range.second,
                                 range.first, range.second,
                                 res, c);
}

template <typename In, typename In2, typename Out>
Out set_difference(input_sequence_range<In> range,
                   input_sequence_range<In2> range2,
                   Out res)
{
    return std::set_difference(range.first, range.second,
                               range.first, range.second,
                               res);
}

template <typename In, typename In2, typename Out, typename Cmp>
Out set_difference(input_sequence_range<In> range,
                   input_sequence_range<In2> range2,
                   Out res, Cmp c)
{
    return std::set_difference(range.first, range.second,
                               range.first, range.second,
                               res, c);
}

template <typename In, typename In2, typename Out>
Out set_symmetric_difference(input_sequence_range<In> range,
                             input_sequence_range<In2> range2,
                             Out res)
{
    return std::set_symmetric_difference(range.first, range.second,
                                         range.first, range.second,
                                         res);
}

template <typename In, typename In2, typename Out, typename Cmp>
Out set_symmetric_difference(input_sequence_range<In> range,
                             input_sequence_range<In2> range2,
                             Out res, Cmp c)
{
    return std::set_symmetric_difference(range.first, range.second,
                                         range.first, range.second,
                                         res, c);
}

template <typename Ran>
void push_heap(input_sequence_range<Ran> range)
{
    std::push_heap(range.first, range.second);
}

template <typename Ran, typename Cmp>
void push_heap(input_sequence_range<Ran> range, Cmp c)
{
    std::push_heap(range.first, range.second, c);
}

template <typename Ran>
void pop_heap(input_sequence_range<Ran> range)
{
    std::pop_heap(range.first, range.second);
}

template <typename Ran, typename Cmp>
void pop_heap(input_sequence_range<Ran> range, Cmp c)
{
    std::pop_heap(range.first, range.second, c);
}

template <typename Ran>
void make_heap(input_sequence_range<Ran> range)
{
    std::make_heap(range.first, range.second);
}

template <typename Ran, typename Cmp>
void make_heap(input_sequence_range<Ran> range, Cmp c)
{
    std::make_heap(range.first, range.second, c);
}

template <typename Ran>
void sort_heap(input_sequence_range<Ran> range)
{
    std::sort_heap(range.first, range.second);
}

template <typename Ran, typename Cmp>
void sort_heap(input_sequence_range<Ran> range, Cmp c)
{
    std::sort_heap(range.first, range.second, c);
}

template <typename Fwd>
Fwd min_element(input_sequence_range<Fwd> range)
{
    return std::min_element(range.first, range.second);
}

template <typename Fwd, typename Cmp>
Fwd min_element(input_sequence_range<Fwd> range, Cmp c)
{
    return std::min_element(range.first, range.second, c);
}

template <typename Fwd>
Fwd max_element(input_sequence_range<Fwd> range)
{
    return std::max_element(range.first, range.second);
}

template <typename Fwd, typename Cmp>
Fwd max_element(input_sequence_range<Fwd> range, Cmp c)
{
    return std::max_element(range.first, range.second, c);
}

template <typename In, typename In2>
bool lexicographical_compare(input_sequence_range<In> range,
                             input_sequence_range<In2> range2)
{
    return std::lexicographical_compare(range.first, range.second,
                                        range2.first, range2.second);
}

template <typename In, typename In2, typename Cmp>
bool lexicographical_compare(input_sequence_range<In> range,
                             input_sequence_range<In2> range2,
                             Cmp c)
{
    return std::lexicographical_compare(range.first, range.second,
                                        range2.first, range2.second,
                                        c);
}

template <typename Bi>
bool next_permutation(input_sequence_range<Bi> range)
{
    return std::next_permutation(range.first, range.second);
}

template <typename Bi, typename Cmp>
bool next_permutation(input_sequence_range<Bi> range, Cmp c)
{
    return std::next_permutation(range.first, range.second, c);
}

template <typename Bi>
bool prev_permutation(input_sequence_range<Bi> range)
{
    return std::prev_permutation(range.first, range.second);
}

template <typename Bi, typename Cmp>
bool prev_permutation(input_sequence_range<Bi> range, Cmp c)
{
    return std::prev_permutation(range.first, range.second, c);
}

} // namespace wt

#endif // ALGORITHM_ISEQ_HH_
