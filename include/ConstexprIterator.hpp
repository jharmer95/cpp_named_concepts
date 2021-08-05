#pragma once

#include <type_traits>

namespace concepts
{
// TODO: Not actually sure about this one
template<typename It>
concept ConstexprIterator = requires(It i)
{
    std::is_constant_evaluated();
};
} // namespace concepts
