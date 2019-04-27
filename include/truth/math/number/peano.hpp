// Copyright (c) 2019 Daniel Krawisz
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef TRUTH_NUMBER_PEANO
#define TRUTH_NUMBER_PEANO

#include <truth/elem.hpp>
#include <truth/equal.hpp>
#include <truth/implies.hpp>
#include <truth/contradiction.hpp>
#include <truth/for_all.hpp>
#include <truth/math/zero.hpp>

namespace truth {
    
    namespace math {
        
        namespace number {
    
            template <typename A, typename B> struct And;
    
            template <typename A, typename B> struct Or;
            
            template <typename X> struct Successor;
            
            namespace peano {
            
                template <typename N> const extern 
                Elem<Zero, N> axiom_zero_is_natural;
                
                template <typename N, typename n> extern
                Implies<And<
                        Equal<Zero, Successor<n>>,
                        Elem<n, N>>,
                    Contradiction> axiom_zero_not_succesor;
                
                template <typename N, typename a, typename b> const extern
                Implies<And<Elem<a, N>, Equal<a, b>>, Elem<b, N>> axiom_closed;
                
                template <typename N, typename a, typename b> const extern
                Implies<And<Elem<a, N>, Elem<b, N>, Equal<a, b>>,
                    Equal<Successor<a>, Successor<b>>> axiom_successor_injection_1;
                
                template <typename N, typename a, typename b>
                Implies<And<Elem<a, N>, Elem<b, N>, Equal<Successor<a>, Successor<b>>>,
                    Equal<a, b>> axiom_successor_injection_2;
                
                template <typename N, typename P, typename n> 
                ForAll<n, proposition<P, n>> induction(
                    typename meta::replace<P, n, Zero>::value,
                    Implies<P, meta::replace<P, n, Successor<n>>>);
                
            }
            
        }
        
    };
    
}

#endif 
