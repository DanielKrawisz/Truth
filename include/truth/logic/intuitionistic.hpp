// Copyright (c) 2019 Daniel Krawisz
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef TRUTH_LOGIC_INTUINISTIC
#define TRUTH_LOGIC_INTUINISTIC

namespace truth {
    
    // Intuitionistic logic is the framework that connects programming to proofs. 
    // In intuitionistic logic, a proposition P is always a claim not only that 
    // P is true, but that a proof exists for P. This makes intuitionistic logic
    // more restrictive than the Boolean logic that programmers are more 
    // familiar with. 
    
    namespace logic {
        
        // Intuitionistic logic uses 5 words, although Not is defined in terms of
        // of other words so there are really only four independent words. 
    
        // And means that all parameter types have proofs. 
        template <typename ...> struct And;
    
        // Or means that at least one parameter type has a proof. 
        template <typename ...> struct Or;
        
        // Implies is a function which transforms one kind of proof into another. 
        template <typename, typename ...> struct Implies;
        
        // Contradiction is an unconstructible type. 
        struct Contradiction;
        
        // Not<P> means that a proof of P would imply that a contradiction can be constructed. 
        template <typename X> using Not = Implies<X, Contradiction>;
    
        // Because it is possible for neither a proposition nor its negation to have a proof, 
        // in is not the case that P || !P in intuitionistic logic nor is it the case that 
        // !!P => P. 
        
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
