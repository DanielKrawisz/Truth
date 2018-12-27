#ifndef TRUTH_LOGIC_NOT_HPP
#define TRUTH_LOGIC_NOT_HPP

#include <truth/logic/contradiction.hpp>
#include <truth/logic/implies.hpp>

namespace truth {
     
    namespace logic {
        template <typename X>
        using Not = Implies<X, contradiction>;
    }
    
}

#endif
