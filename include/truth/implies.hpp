#ifndef TRUTH_IMPLIES
#define TRUTH_IMPLIES

namespace truth {
    
    template <typename A, typename B> struct Implies;

    template <typename A, typename B>
    inline B call(Implies<A, B>& fun, A arg) {
        return fun(arg);
    }
    
    template <typename A, typename B, typename C>
    Implies<A, C>& trans(Implies<A, B>&, Implies<B, C>&);
    
}

#endif 
