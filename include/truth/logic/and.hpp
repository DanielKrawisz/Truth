#ifndef TRUTH_LOGIC_AND
#define TRUTH_LOGIC_AND

namespace truth {
    
    namespace logic {
        
        template <typename A, typename B>
        struct And {
            A Left;
            B Right;
                
            And(A a, B b) : Left{a}, Right{b} {}
        };
    }
}

#endif 
