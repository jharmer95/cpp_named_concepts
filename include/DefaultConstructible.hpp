#pragma once

#include <type_traits>

namespace concepts
{
template<typename T>
concept DefaultConstructible = std::is_default_constructible_v<T>;
} // namespace concepts
