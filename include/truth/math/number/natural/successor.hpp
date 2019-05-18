// Copyright (c) 2019 Daniel Krawisz
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef TRUTH_NUMBER_SUCESSOR
#define TRUTH_NUMBER_SUCESSOR

#include <truth/function.hpp>

namespace truth {
    
    namespace math {
        
        namespace number {
            
            namespace natural {
                
                template <typename N> struct successor : data::function::abstract<N, N> {
                    N operator()(N n) {
                        return n + 1;
                    }
                    
                    bool operator==(function<N, N> f) const {
                        return this == &f || dynamic_cast<successor<N>*>(&f) != nullptr;
                    }
                };
                
            }
            
        }
        
    };
    
}

#endif 

