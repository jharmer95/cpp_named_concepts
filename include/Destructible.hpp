#pragma once

#include <type_traits>

namespace concepts
{
template<typename T>
concept Destructible = std::is_destructible_v<T>;
} // namespace concepts
