// Copyright (c) 2019 Daniel Krawisz
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef TRUTH_ELEM
#define TRUTH_ELEM

namespace truth {
    
    // elem<x, X> asserts that x is an element of X.
    // 
    // elem<x, X> cannot be constructed unless x is
    // a construction of an instance of type X. 
    template <typename x, typename X>
    struct Elem {
        operator X() const {
            return x{};
        }
    };
    
}

#endif 
