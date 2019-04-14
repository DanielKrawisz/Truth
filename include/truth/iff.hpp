#ifndef TRUTH_EQUAL
#define TRUTH_EQUAL

#include <truth/implies.hpp>

namespace truth {
    
    template <typename A, typename B> struct Iff;
        
    template <typename A, typename B>
    Implies<A, B>& left(Iff<A, B>&);
        
    template <typename A, typename B>
    Implies<B, A>& right(Iff<A, B>&);
        
    template <typename A, typename B>
    Iff<B, A> reverse(Iff<A, B>&);
    
    template <typename A, typename B, typename C>
    Iff<A, C>& trans(Iff<A, B>&, Iff<B, C>&);
    
}

#endif 
