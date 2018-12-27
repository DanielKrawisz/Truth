#ifndef TRUTH_TYPES_HPP
#define TRUTH_TYPES_HPP

#include <vector>
#include <memory>
#include <string>

namespace truth 
{
    
    template<typename X>
    using vector = const std::vector<X>;

    using byte = uint8_t;

    template<typename X>
    using ptr = const std::shared_ptr<X>;

    using string = const std::string;
    
    using N = unsigned long long int;

}

#endif
