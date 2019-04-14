#ifndef TRUTH_ELEMENT
#define TRUTH_ELEMENT

namespace truth {
    
    template <typename x, typename X> struct Element; 
    
    template <typename x, typename X>
    inline X value(Element<x, X> e) {
        return e.Value;
    };
    
}

#endif 
