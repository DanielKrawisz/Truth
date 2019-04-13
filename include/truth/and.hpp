#ifndef TRUTH_AND
#define TRUTH_AND

namespace truth {
    
    template <typename ...> struct And;
        
    template <typename A, typename B>
    A left(And<A, B>);
        
    template <typename A, typename B>
    B right(And<A, B>);
        
    template <typename A, typename B>
    And<B, A> reverse(And<A, B>);
    
}

#endif 
