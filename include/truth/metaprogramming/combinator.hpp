#ifndef TRUTH_METAPROGRAMMING_COMBINATOR_HPP
#define TRUTH_METAPROGRAMMING_COMBINATOR_HPP

#include <truth/identity.hpp>
#include <truth/constant.hpp>
#include <truth/operate.hpp>

namespace truth {
    
    namespace combinator {
        
        struct I : public identity {};
        
        struct K {
            template <typename X>
            X operator()(X x) const {
                return constant<X>{x};
            }
        };
        
        struct S {
            template <typename function>
            struct operand {
                function Function;
                
                template <typename argument>
                operate<function, argument> operator()(argument arg) {
                    return operate<function, argument>{Function, arg};
                }
            };
            
            template <typename X>
            X operator()(X x) const {
                return operand<X>{x};
            }
        };
        
        template <typename ...> struct reduction;
        
        template <typename X> struct reduction<I, X> {
            using Result = X;
            
            template <typename Z>
            Result operator()(Z z) const {
                return Result{}(z);
            }
        };
        
        template <typename x, typename y> struct reduction<K, x, y> {
            using Result = x;
            
            template <typename A>
            Result operator()(A a) const {
                return Result{}(a);
            }
        };
        
        template <typename X, typename Y, typename Z> struct reduction<S, X, Y, Z> {
            using Result = typename reduction<X, Y, typename reduction<Y, Z>::Result>::Result;
            
            template <typename A>
            Result operator()(A a) const {
                return Result{}(a);
            }
        };
        
        template <typename X, typename Y, typename Z> struct reduction<reduction<X, Y>, Z> {
            using Result = typename reduction<X, Y, Z>::Result;
            
            template <typename A>
            Result operator()(A a) const {
                return Result{}(a);
            }
        };
        
    }
    
}

#endif
