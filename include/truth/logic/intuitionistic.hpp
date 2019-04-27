// Copyright (c) 2019 Daniel Krawisz
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef TRUTH_LOGIC_INTUINISTIC
#define TRUTH_LOGIC_INTUINISTIC

#include <truth/implies.hpp>
#include <truth/contradiction.hpp>

namespace truth {
    
    template <typename A, typename B> struct And;
    
    template <typename A, typename B> struct Or;
    
    namespace intuitionistic {
            
        template <typename x, typename y>
        extern Implies<x, Implies<y, x>> axiom_then_1;
            
        template <typename x, typename y, typename z>
        extern Implies<Implies<x, Implies<y, z>>, Implies<Implies<x, y>, Implies<x, z>>> axiom_then_2;
            
        template <typename x, typename y>
        extern Implies<And<x, y>, x> axiom_and_1;
            
        template <typename x, typename y>
        extern Implies<And<x, y>, y> axiom_and_2;
            
        template <typename x, typename y>
        extern Implies<x, Implies<y, And<x, y>>> axiom_and_3;
            
        template <typename x, typename y>
        extern Implies<x, Or<x, y>> axiom_or_1;
            
        template <typename x, typename y>
        extern Implies<y, Or<x, y>> axiom_or_2;
            
        template <typename x, typename y, typename z>
        extern Implies<Implies<x, z>, Implies<Implies<y, z>, Implies<Or<x, y>, z>>> axiom_or_3;
            
        template <typename X> 
        extern Implies<Contradiction, X> axiom_alse;
        
    }
    
}

#endif
