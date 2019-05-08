// Copyright (c) 2019 Daniel Krawisz
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef TRUTH_FUNCTION
#define TRUTH_FUNCTION

#include <truth/contradiction.hpp>
#include <truth/types.hpp>

namespace truth {
    
    // function from x to y. 
    template<typename x, typename y> using function = data::function::abstract<x, y>&;
    
    template <typename x>
    struct impossible : data::function::abstract<x, Contradiction> {
        Contradiction operator()(x) {
            throw impossibility{write<x>{}()};
        }
    };
    
    template <typename x, typename y, typename z>
    struct composition : data::function::abstract<x, z> {
        function<x, y> f;
        function<y, z> g;
        
        y operator()(x arg) const noexcept {
            return f(g(arg));
        }
    };

}

#endif
