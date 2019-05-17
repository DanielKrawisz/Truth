// Copyright (c) 2019 Daniel Krawisz
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef TRUTH_FUNCTION
#define TRUTH_FUNCTION

#include <truth/contradiction.hpp>
#include <truth/types.hpp>

namespace truth {
    
    // construction of a function call.  
    template<typename f, typename x> struct call {
        operator typename f::range() {
            return f{}(static_cast<typename f::domain>(x{}));
        };
    };

}

#endif
