#pragma once

#include <type_traits>

namespace concepts
{
template<typename T>
concept MoveConstructible = std::is_move_constructible_v<T>;
} // namespace concepts
