#ifndef TRUTH_NUMBER_PEANO
#define TRUTH_NUMBER_PEANO

#include <truth/element.hpp>
#include <truth/equal.hpp>
#include <truth/implies.hpp>
#include <truth/and.hpp>
#include <truth/contradiction.hpp>
#include <truth/for_all.hpp>
#include <truth/math/zero.hpp>

namespace truth {
    
    namespace math {
        
        namespace number {
            
            template <typename N> struct Natural; 
            
            template <typename X> struct Successor;
            
            namespace peano {
            
                template <typename N> extern Element<Zero, Natural<N>> zero;
                
                template <typename N, typename n>
                Impossible<And<Equal<Zero, Successor<n>>, Element<n, N>>> zero_not_succesor {};
                
                template <typename N, typename a, typename b> 
                Element<b, N> closed(Element<a, N>, Equal<a, b>);
                
                template <typename N, typename n>
                Element<Successor<n>, N> successor(Element<n, N>);
                
                template <typename N, typename a, typename b>
                Equal<Successor<a>, Successor<b>> injection(Element<a, N>, Element<b, N>, Equal<a, b>);
                
                template <typename N, typename a, typename b>
                Equal<a, b> injection(Element<a, N>, Element<b, N>, Equal<Successor<a>, Successor<b>>);
                
                template <typename N, typename P, typename n> 
                ForAll<n, proposition<P, n>> induction(
                    typename replace<P, n, Zero>::value,
                    Implies<P, replace<P, n, Successor<n>>>);
                
            }
            
        }
        
    };
    
}

#endif 
