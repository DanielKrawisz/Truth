#ifndef TRUTH_METAPROGRAMMING_METAPROGRAMMING_HPP
#define TRUTH_METAPROGRAMMING_METAPROGRAMMING_HPP

#include <type_traits>

namespace truth {
    
    namespace metaprogramming {
        
        namespace low {
            
            template <typename A, typename B, bool b>
            struct If {
                static const B Result;
            };
            
            template <typename A, typename B>
            struct If<A, B, true> {
                static const A Result;
            };
            
        }
        
        // constructs type A if type cond is constructible, otherwise constructs type B>
        template <typename cond, typename A, typename B> 
        struct If {
            struct innerA {
                cond Condition;
                using Branch = A;
            };
            
            struct innerB {
                using Branch = B;
            };
            
            using Result = typename low::If<innerA, innerB, true>::Result::Branch;
        };
        
        // type that can be constructed. 
        struct possible {};
        
        // type that cannot be constructed. 
        struct impossible {
            impossible() = delete;
        };
        
        //type that can only be constructed if X cannot be 
        // constructed. 
        template <typename X>
        struct unconstructable {
            static const If<X, impossible, possible> Result{};
        };
        
        // type that can only be constructed if two types are equal.
        template <typename x, typename y> struct Equal;
        
        template <typename x> struct Equal<x, x>{};
        
    }
    
}

#endif
