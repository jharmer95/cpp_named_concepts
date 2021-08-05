#pragma once

#include "Allocator.hpp"

#include <concepts>
#include <memory>

namespace concepts
{
template<typename T, typename A>
concept Erasable = requires(A m, T* p)
{
    { std::allocator_traits<A>::destroy(m, p) };
};
} // namespace concepts
