#ifndef TRUTH_LOGIC_AND
#define TRUTH_LOGIC_AND

namespace truth {
    
    namespace logic {
        
        template <typename AND, typename A, typename B>
        struct And {
            static const AND forward(A a, B b) {
                return AND{a, b};
            }
            
            static const AND backward(A a, B b) {
                return AND{b, a};
            }
        };

    }
}

#endif 
