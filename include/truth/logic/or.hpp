#ifndef TRUTH_LOGIC_OR
#define TRUTH_LOGIC_OR

namespace truth {
    
    namespace logic {
        
        template <typename A, typename B>
        struct Or {
            Or(A) {}
            Or(B) {}
        };
        
    }
    
}

#endif 
