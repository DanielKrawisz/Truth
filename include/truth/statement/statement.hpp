#ifndef TRUTH_STATEMENT_STATEMENT_HPP
#define TRUTH_STATEMENT_STATEMENT_HPP

#include <truth/types.hpp>

namespace truth {
    
    namespace statement {
        
        template <typename statement, typename ...> struct writer;
        
        // an expression is any type that 
        template <typename X> struct expression {
            static writer<X> Writable{};
        };
        
        template <typename X>
        struct writer<X&> {
            static string read() {
                return writer<X>{}::write();
            }
        };
        
        template <typename X>
        struct writer<X*> {
            static string read() {
                return writer<X>{}::write();
            }
        };
        
        template <typename statement>
        string write() {
            writer<statement>{}::write();
        }
    
    }
    
}

#endif
