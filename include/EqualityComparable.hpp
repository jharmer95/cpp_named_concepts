#pragma once

#include <concepts>

namespace concepts
{
template<typename T>
concept EqualityComparable = std::equality_comparable<T>;

template<typename T, typename U>
concept EqualityComparableWith = std::equality_comparable_with<T, U>;
} // namespace concepts
