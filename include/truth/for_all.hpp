#ifndef TRUTH_NUMBER_FOR_ALL
#define TRUTH_NUMBER_FOR_ALL

namespace truth {
    
    template <typename R, typename x, typename y> struct replace<R, x, y>;
    
    template <typename x, typename y> struct replace<x, x, y> {
        using value = y;
    };
    
    template <typename n, typename P> struct ForAll;
    
    template <typename P, typename n> struct proposition;
    
    template <typename n, typename P, typename x> typename replace<P, x, n>::value bind(ForAll<n, proposition<P, x>>, n);
    
}

#endif 
