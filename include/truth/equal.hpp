#ifndef TRUTH_EQUAL
#define TRUTH_EQUAL

#include <truth/not.hpp>

namespace truth {
    
    template <typename ...> struct Equal;
    
    template <typename A> struct Equal<A, A> {};
        
    template <typename A, typename B>
    Equal<B, A> reverse(Equal<A, B>);
    
    template <typename A, typename B, typename C>
    Equal<A, C>& trans(Equal<A, B>&, Equal<B, C>&);
    
    template <typename ...X> struct Unequal : public Not<Unequal<X...>>{};
        
    template <typename A, typename B>
    Uneual<B, A> reverse(Unequal<A, B>);
    
}

#endif 
