#ifndef TRUTH_STATEMENT_OPERATION_HPP
#define TRUTH_STATEMENT_OPERATION_HPP

#include <truth/statement/statement.hpp>
#include <truth/statement/operand.hpp>

namespace truth {
    
    namespace statement {
        
        template <typename ...> struct operation;
        
        template <typename op, typename X> struct operation<op, X> : public operand::unary<op> {};
        
        template <typename op, typename X, typename Y> struct operation<op, X, Y> : public operand::binary<op> {};
        
        template <typename op, typename first, typename ... rest> struct operation<op, first, rest...> : public operand::associative<op>, public operation<op, rest...> {};
        
        template <typename X, typename op> struct add_parentheses {};
        
        template <typename X, typename op>
        struct writer<add_parentheses<X, op>> {
            static string write() {
                return statement::write<X>();
            }
        };
            
        template <typename op, typename X>
        struct writer<operation<op, X>> {
            static string write() {
                return operand::write<op>() + statement::write<add_parentheses<X, op>>();
            }
        };
            
        template <typename op, typename X, typename Y>
        struct writer<operation<op, X, Y>> {
            static string read() {
                return statement::write<add_parentheses<X, op>>() + operand::write<op>() + statement::write<add_parentheses<X, op>>();
            }
        };
    
    }
    
}

#endif
