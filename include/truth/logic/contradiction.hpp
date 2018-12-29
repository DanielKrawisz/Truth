#ifndef TRUTH_LOGIC_CONTRADICTION_HPP
#define TRUTH_LOGIC_CONTRADICTION_HPP

#include <truth/statement/statement.hpp>
#include <exception>

namespace truth {
     
    namespace logic {
        // type that cannot exist. 
        struct contradiction {
            contradiction() = delete;
        };
    }
        
    // type that can only exist by being thrown. 
    class impossibility : std::exception {
        string What;
        impossibility(string w) : What{w} {}
                
    public:
        const char* what() const noexcept final override {
            return What.c_str();
        }
                
        static logic::contradiction contradict(string What) {
            throw impossibility{What};
        };
    };
    
    namespace statement {
        
        template<>
        struct writer<impossibility> {
            string read() const {
                return "impossibile"; 
            }
        };
    
    }
    
}

#endif
