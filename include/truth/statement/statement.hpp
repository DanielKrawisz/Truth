#ifndef TRUTH_STATEMENT_STATEMENT_HPP
#define TRUTH_STATEMENT_STATEMENT_HPP

#include <truth/types.hpp>

namespace truth {
    
    namespace statement {
        
        template <typename statement, typename ...> struct reader;
        
        template <typename X>
        struct reader<X&> {
            static string read() {
                return reader<X>{}::read();
            }
        };
        
        template <typename X>
        struct reader<X*> {
            static string read() {
                return reader<X>{}::read();
            }
        };
        
        template <typename statement>
        string read() {
            reader<statement>{}::read();
        }
    
    }
    
}

#endif
