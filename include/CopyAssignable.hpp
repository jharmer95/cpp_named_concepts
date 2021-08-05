#pragma once

#include <type_traits>

namespace concepts
{
template<typename T>
concept CopyAssignable = std::is_copy_assignable_v<T>;
} // namespace concepts
