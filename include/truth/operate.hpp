#ifndef TRUTH_OPERATE_HPP
#define TRUTH_OPERATE_HPP

namespace truth 
{

    template <typename function, typename argument>
    struct operate {
        function Function;
        argument Argument;
                
        template <typename result, typename environment>
        result operator()(environment z) {
            return Function(z)(Argument(z));
        }
    };

}

#endif
