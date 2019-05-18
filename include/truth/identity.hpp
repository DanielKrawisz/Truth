// Copyright (c) 2019 Daniel Krawisz
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef TRUTH_IDENTITY
#define TRUTH_IDENTITY

#include <truth/function.hpp>

namespace truth {

    // we can always construct the identity function. 
    template <typename X> using identity = data::identity<X>;

}

#endif
