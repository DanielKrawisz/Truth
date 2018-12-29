#ifndef TRUTH_LOGIC_IMPLIES_HPP
#define TRUTH_LOGIC_IMPLIES_HPP

#include <truth/statement/operation.hpp>
#include <truth/function.hpp>

namespace truth {
     
    namespace logic {
        
        // implies is both a function and a statement.
        template <typename imp, typename X, typename Y>
        struct Implies : public function<imp, X, Y> {
            static const statement::expression<imp> Expression{};
        };
    }
    
}

#endif
