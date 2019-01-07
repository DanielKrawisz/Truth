#ifndef TRUTH_METAPROGRAMMING_WHICH_HPP
#define TRUTH_METAPROGRAMMING_WHICH_HPP

#include "metaprogramming.hpp"

namespace truth {
    
    namespace metaprogramming {
        
        // contains the first constructable type in a list. 
        template <typename first, typename ... rest> 
        struct Which {
            using Result = typename If<first, first, typename Which<rest...>::Result>::Result;
        };
        
        template <typename X> struct Which<X> {
            using Result = X;
        };
        
    }
    
}

#endif

