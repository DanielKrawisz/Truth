#ifndef TRUTH_TYPES
#define TRUTH_TYPES

#include <vector>
#include <memory>
#include <string>
#include <meta/format.hpp>

namespace truth {
    
    template<typename X>
    using vector = const std::vector<X>;

    using byte = uint8_t;

    template<typename X>
    using ptr = const std::shared_ptr<X>;
    
    using symbol = char32_t;

    using string = const std::u32string;
    
    using uint = unsigned long long int;
    
    struct Truth;
    
    template <typename T>
    using write = meta::format::write<T, string, Truth>;
    
    template <typename T>
    using read = meta::format::read<T, string, Truth>;

}

#endif
