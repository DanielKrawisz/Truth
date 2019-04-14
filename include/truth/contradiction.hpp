#ifndef TRUTH_LOGIC_CONTRADICTION_HPP
#define TRUTH_LOGIC_CONTRADICTION_HPP

#include <exception>
#include <truth/types.hpp>

namespace truth {
     
    // type that cannot exist. 
    struct Contradiction {
        Contradiction() = delete;
    };
    
    template <typename T> struct impossible;
        
    // type that can only exist by being thrown. 
    class impossibility : std::exception {
        string What;
        impossibility(string w) : What{w} {}
        
    public:
        const char* what() const noexcept final override {
            return What.c_str();
        }
        
        template <typename T>
        friend struct impossible;
    };
    
    template <typename T>
    string write();
    
    template <typename T>
    struct Impossible {
        Contradiction operator()(T) {
            throw impossibility{write<T>()};
        }
    };
    
}

#endif
