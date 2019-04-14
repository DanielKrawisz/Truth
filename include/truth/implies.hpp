#ifndef TRUTH_IMPLIES
#define TRUTH_IMPLIES

#include <truth/identity.hpp>

namespace truth {
    
    template <typename A, typename B> struct Implies;
    
    template <typename A> struct Implies<A, A> : identity {};

    template <typename A, typename B>
    inline B call(Implies<A, B>& fun, A arg) {
        return fun(arg);
    }
    
    template <typename A, typename B, typename C>
    Implies<A, C>& trans(Implies<A, B>&, Implies<B, C>&);
    
}

#endif 
