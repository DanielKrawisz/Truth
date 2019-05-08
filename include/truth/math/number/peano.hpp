// Copyright (c) 2019 Daniel Krawisz
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef TRUTH_NUMBER_PEANO
#define TRUTH_NUMBER_PEANO

#include <truth/elem.hpp>
#include <truth/contradiction.hpp>
#include <truth/for_all.hpp>
#include <truth/math/zero.hpp>

namespace truth {
    
    namespace logic {
        
        template <typename ...> struct And;

        template <typename ...> struct Or;
        
        template <typename, typename ...> struct Implies;
            
        template <typename, typename> struct Equal;

    }
    
    namespace math {
        
        namespace number {
    
            template <typename ...p> using And = logic::And<p...>;
    
            template <typename ...p> using Or = logic::Or<p...>;
            
            template <typename domain, typename ...range> using Implies = logic::Implies<domain, range...>;
            
            template <typename a, typename b> using Equal = struct logic::Equal<a, b>;
            
            template <typename X> struct Suc;
            
            template <typename, typename> struct proposition;
            
            namespace peano {
            
                template <typename N> const extern 
                Elem<Zero, N> axiom_zero_is_natural;
                
                template <typename N, typename n> extern
                Implies<And<
                        Equal<Zero, Suc<n>>,
                        Elem<n, N>>,
                    Contradiction> axiom_zero_not_succesor;
                
                template <typename N, typename a, typename b> extern
                Implies<And<Elem<a, N>, Equal<a, b>>, Elem<b, N>> axiom_closed;
                
                template <typename N, typename a, typename b> extern
                Implies<And<Elem<a, N>, Elem<b, N>, Equal<a, b>>,
                    Equal<Suc<a>, Suc<b>>> axiom_successor_injection_1;
                
                template <typename N, typename a, typename b> extern
                Implies<And<Elem<a, N>, Elem<b, N>, Equal<Suc<a>, Suc<b>>>,
                    Equal<a, b>> axiom_successor_injection_2;
                
                template <typename N, typename P, typename n> 
                ForAll<n, proposition<P, n>> induction(
                    typename meta::replace<P, n, Zero>::value,
                    Implies<P, meta::replace<P, n, Suc<n>>>);
                
            }
            
        }
        
    };
    
}

#endif 
