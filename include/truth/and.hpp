// Copyright (c) 2019 Daniel Krawisz
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef TRUTH_AND
#define TRUTH_AND

#include <data/tuple.hpp>
#include <meta/replace.hpp>

namespace truth {
    
    template <typename ...props> struct And;
        
    template <> struct And<> : public data::tuple<> {
        template <typename X> using prepend = And<X>;
    };
        
    template <typename first> struct And<first> : public data::tuple<first> {
        first First; 
            
        And(first p) : First{p} {}
            
        operator first(){
            return First;
        }
            
        template <typename X> using prepend = And<X, first>;
    };
        
    template <typename first, typename ...rest> struct And<first, rest...> : public data::tuple<first, rest...> {
        first First;
        And<rest...> Rest;
            
        And(first f, rest... r) : First{f}, Rest{And<rest...>{r...}} {}
            
        template <typename X> using prepend = And<X, first, rest...>;
    };
    
}

namespace meta {
    template <typename a, typename b, typename first, typename ...rest> 
    struct replace<truth::And<first, rest...>, a, b> {
        using result = typename replace<truth::And<rest...>, a, b>::result::template prepend<replace<first, a, b>>;
    }; 
}

#endif 
