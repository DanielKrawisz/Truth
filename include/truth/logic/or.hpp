// Copyright (c) 2019 Daniel Krawisz
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef TRUTH_LOGIC_OR
#define TRUTH_LOGIC_OR

#include <truth/logic/and.hpp>
#include <truth/function.hpp>

namespace truth {
    
    namespace logic {
        
        namespace meta {
            
            template <typename ...props> struct Or;
        
            template <typename first> struct Or<first> {
                Or(first) {}
                template <typename X> using prepend = Or<X, first>;
                template <typename X> using function_type = And<function<first, X>>;
            };
        
            template <typename first, typename... rest> struct Or<first, rest...> : public Or<rest...> {
                using Or<rest...>::Or; // inherit constructors.
                Or(first) {}
                template <typename X> using prepend = Or<X, first, rest...>;
                template <typename X> using parent_function_type = typename Or<rest...>::function_type;
                template <typename X> using function_type = typename parent_function_type<X>::template prepend<function<first, X>>;
            };
        
            template <typename true_type, typename... or_types> struct or_derived final : public Or<or_types...> {
                true_type Truth;
                or_derived(true_type t) : Or<or_types...>{t}, Truth{t} {}
            };

            template <typename out, typename first, typename... rest> struct apply_or_function {
                out operator()(Or<first, rest...>& o, typename Or<first, rest...>::function_type f) {
                    or_derived<first, first, rest...>* od = dynamic_cast<or_derived<first, first, rest...>*>(&o);
                    if (od != nullptr) return std::get<function<first, out>>(f)(od->Truth);
                    return apply_or_function<out, rest...>{}(static_cast<Or<rest...>&>(o), f.Rest);
                }
            };
            
        }
    
        template <typename ...props> using Or = meta::Or<props...>&;
    
    }
}

namespace meta {
    template <typename a, typename b, typename first, typename ...rest> 
    struct replace<truth::logic::Or<first, rest...>, a, b> {
        using result = typename replace<truth::logic::Or<rest...>, a, b>::result::template prepend<replace<first, a, b>>;
    }; 
}

#endif 

