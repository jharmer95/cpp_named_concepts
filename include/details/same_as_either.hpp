#pragma once

#include <type_traits>

namespace concepts
{
// This namespace is only for helpers, not for actual requirements
namespace details
{
    template<typename T1, typename T2, typename U>
    concept same_as_either = std::is_same_v<T1, U> || std::is_same_v<T2, U>;
}
} // namespace concepts
