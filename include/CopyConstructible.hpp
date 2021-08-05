#pragma once

#include <type_traits>

namespace concepts
{
template<typename T>
concept CopyConstructible = std::is_copy_constructible_v<T>;
} // namespace concepts
