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

#ifdef CONCEPTS_TESTING

#include <vector>

static_assert(concepts::Erasable<typename std::vector<int>::value_type, typename std::vector<int>::allocator_type>);

#endif
