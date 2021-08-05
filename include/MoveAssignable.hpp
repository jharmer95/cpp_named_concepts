#pragma once

#include <type_traits>

namespace concepts
{
template<typename T>
concept MoveAssignable = std::is_move_assignable_v<T>;
} // namespace concepts
