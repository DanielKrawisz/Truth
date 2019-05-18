// Copyright (c) 2019 Daniel Krawisz
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef TRUTH_MATH_ZERO
#define TRUTH_MATH_ZERO

namespace truth {
    
    namespace math {
        
        struct Zero {
            template <typename x>
            operator x() {
                return 0;
            }
        };
        
    };
    
}

#endif 
