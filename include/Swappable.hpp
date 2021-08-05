#pragma once

#include <concepts>

namespace concepts
{
template<typename T>
concept Swappable = std::swappable<T>;

template<typename T, typename U>
concept SwappableWith = std::swappable_with<T, U>;
} // namespace concepts
