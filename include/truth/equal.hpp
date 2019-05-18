// Copyright (c) 2019 Daniel Krawisz
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef TRUTH_EQUAL
#define TRUTH_EQUAL

#include <truth/implies.hpp>
#include <truth/identity.hpp>

namespace truth {
        
    template <typename, typename ...> struct Equal;
    
    template <typename X> struct Equal<X, X> {
        
        operator Implies<X, X>(){
            return *new identity<X>{};
        }
    };

    template <typename A, typename B>
    struct Equal<A, B> {
        Implies<A, B> LeftToRight;
        Implies<B, A> RightToLeft;
        
        Equal(Implies<A, B> lr, Implies<B, A> rl) : LeftToRight{lr}, RightToLeft{rl} {}
        
        operator Equal<B, A>(){
            return {RightToLeft, LeftToRight};
        }
        
        operator Implies<A, B>(){
            return LeftToRight;
        }
        
        operator Implies<B, A>(){
            return RightToLeft;
        }
        
        template <typename C>
        Equal<A, C> transitive(Equal<B, C> e) {
            return {*new composition<A, B, C>{this->LeftToRight, e.LeftToRight}, 
                    *new composition<C, B, A>{e.RightToLeft, this->RightToLeft}};
        }
    };

    template <typename A, typename B, typename ... rest>
    struct Equal<A, B, rest...> {
        Equal<A, B> First;
        Equal<B, rest...> Rest;
        
        Equal(Equal<A, B> f, Equal<B, rest...> r) : First{f}, Rest{r} {}
        
        operator Equal<A, B>(){
            return First;
        }
            
        operator Equal<B, A>(){
            return static_cast<Equal<B, A>>(First);
        }
            
        template <typename C>
        operator Equal<B, C>(){
            return static_cast<Equal<B, C>>(Rest);
        }
            
        template <typename C>
        operator Equal<C, B>(){
            return static_cast<Equal<C, B>>(static_cast<Equal<B, C>>(Rest));
        }
        
        template <typename C>
        operator Equal<A, C>(){
            return First.transitive(static_cast<Equal<B, C>>(Rest));
        }
        
        template <typename C>
        operator Equal<C, A>(){
            return static_cast<Equal<C, A>>(static_cast<Equal<A, C>>(*this));
        }
        
        template <typename C, typename D>
        operator Equal<C, D>(){
            return static_cast<Equal<C, D>>(Rest);
        }
    };

}

namespace meta {
    template <typename x, typename y, typename a, typename b> 
    struct replace<truth::Equal<x, y>, a, b> {
        using result = truth::Equal<
            typename replace<x, a, b>::result,
            typename replace<y, a, b>::result>;
    }; 
}

#endif 
