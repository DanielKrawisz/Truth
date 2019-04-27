// Copyright (c) 2019 Daniel Krawisz
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef TRUTH_LOGIC_CONTRADICTION
#define TRUTH_LOGIC_CONTRADICTION

#include <exception>
#include <truth/types.hpp>

namespace truth {
     
    // a contradiction is type that cannot exist. 
    struct Contradiction final {
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
    
}

#endif
