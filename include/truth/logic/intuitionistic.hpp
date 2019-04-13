#ifndef TRUTH_LOGIC_INTUINISTIC_HPP
#define TRUTH_LOGIC_INTUINISTIC_HPP

#include <truth/and.hpp>
#include <truth/or.hpp>
#include <truth/implies.hpp>
#include <truth/not.hpp>
#include <truth/logic/contradiction.hpp>

namespace truth {
    
    template <typename x> struct Not : Implies<x, logic::contradiction> {};
    
    namespace logic {
        
        namespace intuitionistic {
            
            template <typename x, typename y>
            using then_1 = Implies<x, Implies<x, y>&>;
                
            template <typename x, typename y, typename z>
            using then_2 = Implies<Implies<x, Implies<y, z>&>&, Implies<Implies<x, y>&, Implies<x, z>&>&>;
                
            template <typename x, typename y>
            using and_1 = Implies<And<x, y>, x>;
                
            template <typename x, typename y>
            using and_2 = Implies<And<x, y>, y>;
                
            template <typename x, typename y>
            using and_3 = Implies<x, Implies<y, And<x, y>>&>;
                
            template <typename x, typename y>
            using or_1 = Implies<x, Or<x, y>&>;
                
            template <typename x, typename y>
            using or_2 = Implies<y, Or<x, y>&>;
                
            template <typename x, typename y, typename z>
            using or_3 = Implies<Implies<x, z>&, Implies<Implies<y, z>&, Implies<Or<x, y>&, z>&>&>;
                
            template <typename X> 
            using impossible = Implies<contradiction, X>;
        
        }
        
    }
    
    // assert that all axioms are constructible. 
    template <typename x, typename y>
    struct Implies<x, Implies<x, y>&>;
                
    template <typename x, typename y, typename z>
    struct Implies<Implies<x, Implies<y, z>&>&, Implies<Implies<x, y>&, Implies<x, z>&>&>;
                
    template <typename x, typename y>
    struct Implies<And<x, y>, x>;
                
    template <typename x, typename y>
    struct Implies<And<x, y>, y>;
                
    template <typename x, typename y>
    struct Implies<x, Implies<y, And<x, y>>&>;
                
    template <typename x, typename y>
    struct Implies<x, Or<x, y>&>;
                
    template <typename x, typename y>
    struct Implies<y, Or<x, y>&>;
                
    template <typename x, typename y, typename z>
    struct Implies<Implies<x, z>&, Implies<Implies<y, z>&, Implies<Or<x, y>&, z>&>&>;
                
    template <typename X> 
    struct Implies<logic::contradiction, X>;
    
}

#endif
