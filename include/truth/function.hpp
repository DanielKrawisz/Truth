// Copyright (c) 2019 Daniel Krawisz
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef TRUTH_FUNCTION
#define TRUTH_FUNCTION

#include <truth/contradiction.hpp>

namespace truth {
    
    // function from x to y. 
    template<typename x, typename y> struct function {
        virtual y operator()(const x) const noexcept = 0;
    };
    
    // functions to contradictions are not required to be noexcept.
    template<typename x> struct function<x, Contradiction> {
        virtual const Contradiction operator()(const x) const = 0;
    };
    
    template <typename x>
    struct impossible : function<x, Contradiction> {
        Contradiction operator()(x) {
            throw impossibility{write<x>{}()};
        }
    };
    
    template <typename x, typename y, typename z>
    struct composition : function<x, z> {
        function<x, y> const * f;
        function<y, z> const * g;
        
        y operator()(x arg) const noexcept {
            return f(g(arg));
        }
    };

}

#endif
