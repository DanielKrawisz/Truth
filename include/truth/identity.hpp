#ifndef TRUTH_IDENTITY_HPP
#define TRUTH_IDENTITY_HPP

namespace truth
{

    template <typename X>
    struct identity {
        X operator()(X x) const {
        return x;
    };

}

#endif

