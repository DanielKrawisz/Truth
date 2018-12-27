#ifndef TRUTH_FUNCTION_HPP
#define TRUTH_FUNCTION_HPP

#include <truth/logic/contradiction.hpp>

namespace truth 
{
    
    // function from x to y. 
    template<typename f, typename x, typename y> struct function {
        // type f must be callable, and must take an argument of type x
        // and return an argument of type y. 
        static const y callable(const f fun, const x arg) noexcept {
            return fun(arg);
        }
    }
    
    // functions to contradictions are not required to be noexcept.
    template<typename f, typename x> struct function<f, x, contradiction> {
        static const contradiction callable(const f fun, const x arg) {
            return fun(arg);
        }
    }
    
    // composition is a function. 
    template <typename f, typename g, typename x, typename y>
    struct composition {
        f A;
        g B;
        
        y operator()(x arg) const {
            return A(B(arg));
        }
    };

}

#endif
