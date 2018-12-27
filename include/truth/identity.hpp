#ifndef TRUTH_IDENTITY_HPP
#define TRUTH_IDENTITY_HPP

namespace truth
{

    // we can always construct the identity function. 
    struct identity {
        template <typename X>
        X operator()(X x) const {
            return x;
        }
    };

}

#endif
