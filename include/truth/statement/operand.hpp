#ifndef TRUTH_STATEMENT_OPERAND_HPP
#define TRUTH_STATEMENT_OPERAND_HPP

#include <truth/logic/contradiction.hpp>

namespace truth {
    
    namespace operand {
        
        template <typename op> struct unary;
        template <typename op> struct binary;
        template <typename op> struct associative;
        
        struct Equal {
                static const string symbol() {
                    return "=";
                }
                    
                static const N precedence() {
                    return 290;
            }
        };
        
        template <> struct binary<Equal> {};
        template <> struct associative<Equal> {};
                
        struct Implies {
            static const string symbol() {
                return "=>";
            }
                    
            static const N precedence() {
                return 200;
            }
        };
        
        template <> struct binary<Implies> {};
        template <> struct associative<Implies> {};
            
        struct And {
            static const string symbol() {
                return "^";
            }
                    
            static const N precedence() {
                return 0;
            }
        };
        
        template <> struct binary<And> {};
        template <> struct associative<And> {};
                
        struct Or {
            static const string symbol() {
                return "|";
            }
                    
            static const N precedence() {
                return 215;
            }
        };
        
        template <> struct binary<Or> {};
        template <> struct associative<Or> {};
                
        struct Plus {
            static const string symbol() {
                return "+";
            }
                    
            static const N precedence() {
                return 0;
            }
        };
        
        template <> struct binary<Plus> {};
        template <> struct associative<Plus> {};
                
        struct Times {
            static const string symbol() {
                return "*";
            }
                    
            static const N precedence() {
                return 0;
            }
        };
        
        template <> struct binary<Times> {};
        template <> struct associative<Times> {};
        
        template <typename op>
        inline const string write() {
            return op::symbol();
        }
        
        template <typename op>
        inline const N precedence() {
            return op::precedence();
        }
    
    }
    
}

#endif
