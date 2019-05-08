// Copyright (c) 2019 Daniel Krawisz
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef TRUTH_LOGIC_AND
#define TRUTH_LOGIC_AND

#include <tuple>
#include <meta/replace.hpp>

namespace truth {
    
    namespace logic {
    
        template <typename ...types> struct And;
        
        template <> struct And<> : public std::tuple<> {
            template <typename X> using prepend = And<X>;
        };
        
        template <typename type> struct And<type> : public std::tuple<type> {
            template <typename X> using prepend = And<X, type>;
        };
        
        template <typename first, typename ...rest> struct And<first, rest...> : public std::tuple<first, rest...> {
            template <typename X> using prepend = And<X, first, rest...>;
        };
    
    }
}

namespace meta {
    template <typename a, typename b, typename first, typename ...rest> 
    struct replace<truth::logic::And<first, rest...>, a, b> {
        using result = typename replace<truth::logic::And<rest...>, a, b>::result::template prepend<replace<first, a, b>>;
    }; 
}

#endif 
