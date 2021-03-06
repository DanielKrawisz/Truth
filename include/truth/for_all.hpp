// Copyright (c) 2019 Daniel Krawisz
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef TRUTH_NUMBER_FOR_ALL
#define TRUTH_NUMBER_FOR_ALL

#include <meta/replace.hpp>

namespace truth {
    template <typename exists, typename predicate> struct ForAll;
    
    // Elem asserts that x is an element of X.
    // We don't know how to construct it. 
    template <typename x, typename X> struct Elem;
    
    // ForAll defines a class of types according to a predicate
    // with a variable x and asserts that for any type y, 
    // a new type can be constructed by replacing x with y as
    // long as y is a construction of type X. 
    template <typename x, typename X, typename predicate> struct ForAll<Elem<x, X>, predicate> {
        template <typename y> 
        typename meta::replace<predicate, x, y>::result of(Elem<y, X> e) {
            return typename meta::replace<predicate, x, y>::result{e};
        }
    };
    
}

#endif 
