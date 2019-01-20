#ifndef TRUTH_METAPROGRAMMING_LIST_HPP
#define TRUTH_METAPROGRAMMING_LIST_HPP

#include <truth/metaprogramming/metaprogramming.hpp>

namespace truth {
    
    namespace metaprogramming {
            
        template <typename ...> struct list;
            
        template<> struct list<>{
            using Rest = impossible;
        };

        template <typename first, typename ... rest> struct list<first, rest...> {
            using First = first;
            using Rest = list<rest...>;
        };

        template <typename ...> struct prepend;

        template <typename x, typename ... e> struct prepend<list<e...>, x> {
            using Result = list<x, e...>;
        };

        template <typename ...> struct contains;

        template <typename x> struct contains<list<>, x> {
            static const bool Result = false;
        };

        template <typename x> struct contains<list<x>, x> {
            static const bool Result = true;
        };

        template <typename x, typename y> struct contains<list<y>, x> {
            static const bool Result = false;
        };

        template <typename x, typename ... e> struct contains<list<x, e...>, x> {
            static const bool Result = true;
        };

        template <typename x, typename y, typename ... e> struct contains<list<y, e...>, x> {
            static const bool Result = contains<list<e...>, x>::Result;
        };

    }
    
}

#endif
