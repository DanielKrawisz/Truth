// Copyright (c) 2019 Daniel Krawisz
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef TRUTH_IMPLIES
#define TRUTH_IMPLIES

#include <truth/function.hpp>
#include <meta/replace.hpp>

namespace truth {
    
    template <typename x, typename y> using Implies = function<x, y>&;
    
}

namespace meta {
    template <typename x, typename y, typename a, typename b> 
    struct replace<::truth::Implies<x, y>, a, b> {
        using result = ::truth::Implies<
            typename replace<x, a, b>::result,
            typename replace<y, a, b>::result>;
    }; 
}

#endif 
