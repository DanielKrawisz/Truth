// Copyright (c) 2019 Daniel Krawisz
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef TRUTH_NUMBER_EXISTS
#define TRUTH_NUMBER_EXISTS

#include <meta/replace.hpp>
#include <truth/types.hpp>
#include <truth/and.hpp>

namespace truth {
    // Var represents a construction of something that
    // we don't know what it is. 
    template <symbol> struct Var;
    
    template <typename exists, typename predicate> struct Exists;
    
    // Elem asserts that x is an element of X.
    // We don't know how to construct it. 
    template <typename x, typename X> struct Elem;
    
    // ForAll defines a class of types according to a predicate
    // with a variable x and asserts that for any type y, 
    // a new type can be constructed by replacing x with y as
    // long as y is a construction of type X. 
    template <typename x, typename X, typename predicate> struct Exists<Elem<x, X>, predicate> {
        template <symbol y> 
        And<Elem<Var<y>, X>, typename meta::replace<predicate, x, Var<y>>::result> of();
    };
    
}

#endif 

