// Copyright (c) 2019 Daniel Krawisz
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef TRUTH_LOGIC_INTUINISTIC
#define TRUTH_LOGIC_INTUINISTIC

#include <truth/contradiction.hpp>

namespace truth {
    
    namespace logic {
    
        template <typename ...> struct And;
    
        template <typename ...> struct Or;
        
        template <typename, typename ...> struct Implies;
    
        namespace intuitionistic {
                
            template <typename x, typename y>
            extern Implies<x, y, x> axiom_then_1;
                
            template <typename x, typename y, typename z>
            extern Implies<Implies<x, y, z>, Implies<x, y>, x, z> axiom_then_2;
                
            template <typename x, typename y>
            extern Implies<And<x, y>, x> axiom_and_1;
                
            template <typename x, typename y>
            extern Implies<And<x, y>, y> axiom_and_2;
                
            template <typename x, typename y>
            extern Implies<x, y, And<x, y>> axiom_and_3;
                
            template <typename x, typename y>
            extern Implies<x, Or<x, y>> axiom_or_1;
                
            template <typename x, typename y>
            extern Implies<y, Or<x, y>> axiom_or_2;
                
            template <typename x, typename y, typename z>
            extern Implies<Implies<x, z>, Implies<y, z>, Or<x, y>, z> axiom_or_3;
                
            template <typename X> 
            extern Implies<Contradiction, X> axiom_false;
            
        }
    
    }
    
}

#endif
