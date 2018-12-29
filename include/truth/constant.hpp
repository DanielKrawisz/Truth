#ifndef TRUTH_CONSTANT_HPP
#define TRUTH_CONSTANT_HPP

namespace truth 
{

    template <typename X>
    struct constant {
        X Constant;
        
        template <typename Y>
        X operator()(Y) const {
            return Constant;
        }
    };

}

#endif
