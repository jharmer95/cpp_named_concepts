#pragma once

#include "LegacyIterator.hpp"

#include <concepts>
#include <iterator>
#include <type_traits>

namespace concepts
{
template<typename X>
concept LegacyOutputIterator = requires(X r, std::remove_pointer_t<X> o)
{
    requires LegacyIterator<X>;
    requires std::is_class_v<X> || std::is_pointer_v<X>;

    { *r = o };
    { ++r } -> std::same_as<X&>;
    { r++ } -> std::convertible_to<const X&>;
    { *r++ = o };
};
} // namespace concepts
