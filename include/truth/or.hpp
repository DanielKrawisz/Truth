#ifndef TRUTH_OR
#define TRUTH_OR

namespace truth {
    
    template <typename ...> struct Or;
    
    template <> struct Or<> {};
        
    template <typename A, typename B>
    Or<A, B> left(A);
        
    template <typename A, typename B>
    Or<A, B> right(B);
        
    template <typename A, typename B>
    Or<B, A> reverse(Or<A, B>);
    
}

#endif 
