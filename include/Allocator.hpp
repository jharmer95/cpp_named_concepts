#pragma once

#include "NullablePointer.hpp"
#include "LegacyRandomAccessIterator.hpp"
#include "LegacyContiguousIterator.hpp"

#include <concepts>
#include <memory>

namespace concepts
{
template<typename A>
concept Allocator = requires(A a, A a1, typename A::value_type* p, const typename A::value_type* cp,
    typename A::value_type r, typename std::allocator_traits<A>::size_type n)
{
    { *p } -> std::same_as<typename A::value_type&>;
    { *cp } -> std::same_as<const typename A::value_type&>;

    { std::pointer_traits<typename A::value_type*>::pointer_to(r) };
    { a.allocate(n) } -> std::same_as<typename A::value_type*>;
    { a.deallocate(p, n) };

    { a == a1 } -> std::same_as<bool>;
    { a != a1 } -> std::same_as<bool>;

    { A(a) } noexcept;
    { A(std::move(a)) } noexcept;
};
} // namespace concepts

#ifdef CONCEPTS_TESTING

#include <cstddef>
#include <memory_resource>
#include <string>

static_assert(concepts::Allocator<std::allocator<std::byte>>);
static_assert(concepts::Allocator<std::allocator<std::string>>);
static_assert(concepts::Allocator<std::pmr::polymorphic_allocator<std::byte>>);
static_assert(concepts::Allocator<std::pmr::polymorphic_allocator<std::string>>);

#endif
