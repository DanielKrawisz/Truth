// Copyright (c) 2019 Daniel Krawisz
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef TRUTH_LOGIC_IMPLIES
#define TRUTH_LOGIC_IMPLIES

#include <truth/function.hpp>
#include <meta/replace.hpp>

namespace truth {
        
    template <typename domain, typename ...range> struct implies;
        
    template <typename domain, typename ...range> using Implies = implies<domain, range...>&;
    
    template <typename x, typename y> struct implies<x, y> : public data::function::abstract<x, y> {
        template <typename z> using prepend = implies<z, x, y>;
    };
        
    template <typename x, typename y, typename ...rest> struct implies<x, y, rest...> : public data::function::abstract<x, Implies<y, rest...>> {
        template <typename z> using prepend = implies<z, x, y, rest...>;
    };
}

namespace meta {
    template <typename a, typename b, typename first, typename ...rest> 
    struct replace<truth::Implies<first, rest...>, a, b> {
        using result = typename replace<truth::implies<rest...>, a, b>::result::template prepend<typename replace<first, a, b>::result>&;
    };
    
    template <typename a, typename b, typename domain, typename range> 
    struct replace<truth::Implies<domain, range>, a, b> {
        using result = truth::Implies<
            typename replace<domain, a, b>::result,
            typename replace<range, a, b>::result>;
    }; 
}

#endif 
