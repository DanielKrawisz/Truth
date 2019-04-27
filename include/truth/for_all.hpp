// Copyright (c) 2019 Daniel Krawisz
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef TRUTH_NUMBER_FOR_ALL
#define TRUTH_NUMBER_FOR_ALL

#include <meta/replace.hpp>
#include <truth/elem.hpp>

namespace truth {
    template <typename X, typename predicate> struct ForAll;
    
    // ForAll defines a class of types according to a predicate
    // with a variable x and asserts that for any type y, 
    // a new type can be constructed by replacing x with y as
    // long as y is a construction of type X. 
    template <typename x, typename X, typename predicate> struct ForAll<Elem<x, X>, predicate> {
        template <typename y> 
        typename meta::replace<predicate, x, y>::result of() {
            return typename meta::replace<predicate, x, y>::result{Elem<y, X>{}};
        }
    };
    
}

#endif 
