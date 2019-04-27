#ifndef TRUTH_TYPES
#define TRUTH_TYPES

#include <vector>
#include <memory>
#include <string>
#include <meta/serialize.hpp>

namespace truth {
    
    template<typename X>
    using vector = const std::vector<X>;

    using byte = uint8_t;

    template<typename X>
    using ptr = const std::shared_ptr<X>;

    using string = const std::string;
    
    using N = unsigned long long int;
    
    struct Truth;
    
    template <typename T>
    using write = meta::serialize::write<T, string, Truth>;
    
    template <typename T>
    using read = meta::serialize::write<T, string, Truth>;

}

#endif
