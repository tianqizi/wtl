#ifndef UTILITY_HH_
#define UTILITY_HH_

namespace wt {

// taken from
// http://stackoverflow.com/questions/2552839/which-c-standard-library-wrapper-functions-do-you-use
template<typename T>
struct stash {
    stash(T& val) : hold(val), original(val) { }
    ~stash() { hold = original; }
private:
    stash(const stash&);
    stash& operator=(const stash&);
private:
    T& hold;
    T original;
};
}

#endif /* UTILITY_HH_ */
