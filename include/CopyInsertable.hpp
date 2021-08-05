#pragma once

#include "Allocator.hpp"

#include <memory>

namespace concepts
{
template<typename T, typename A>
concept CopyInsertable = requires(A m, T* p, T(*v)())
{
    { std::allocator_traits<A>::construct(m, p, v()) };
};
} // namespace concepts
