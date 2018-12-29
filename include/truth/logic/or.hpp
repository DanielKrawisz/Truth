#ifndef TRUTH_LOGIC_OR
#define TRUTH_LOGIC_OR

#include <truth/logic/implies.hpp>

namespace truth {
    
    namespace logic {
        
        template <typename OR, typename A, typename B>
        struct Or {
            static const OR left(A a) {
                return OR{a};
            }
            
            static const OR right(B b) {
                return OR{b};
            }
        };
        
    }
    
}

#endif 
