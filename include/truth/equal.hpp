// Copyright (c) 2019 Daniel Krawisz
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef TRUTH_EQUAL
#define TRUTH_EQUAL

#include <truth/implies.hpp>

namespace truth {
    
    template <typename A, typename B>
    struct Equal{
        Implies<A, B> LeftRight;
        Implies<B, A> RightLeft;
        
        operator Equal<B, A>(){
            return {RightLeft, LeftRight};
        }
    };
    
}

namespace meta {
    template <typename x, typename y, typename a, typename b> 
    struct replace<::truth::Equal<x, y>, a, b> {
        using result = ::truth::Equal<
            typename replace<x, a, b>::result,
            typename replace<y, a, b>::result>;
    }; 
}

#endif 
