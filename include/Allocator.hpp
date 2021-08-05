#pragma once

#include "NullablePointer.hpp"
#include "LegacyRandomAccessIterator.hpp"
#include "LegacyContiguousIterator.hpp"

#include <concepts>
#include <memory>

namespace concepts
{
template<template<typename> typename A, typename T>
concept Allocator = requires(A<T> a, A<T> a1, T* p,
    const T* cp, void* vp,
    const void* cvp, T r,
    typename std::allocator_traits<A<T>>::size_type n)
{
    requires NullablePointer<T*> && LegacyRandomAccessIterator<T*> && LegacyContiguousIterator<T*>;
    requires NullablePointer<const T*> && LegacyRandomAccessIterator<const T*> && LegacyContiguousIterator<const T*>;
    requires NullablePointer<void*>;
    requires NullablePointer<const void*>;
    typename A<T>::value_type;

    { *p } -> std::same_as<T&>;
    { *cp } -> std::same_as<const T&>;
    { static_cast<T*>(vp) };
    { static_cast<const T*>(cvp) };

    { std::pointer_traits<T*>::pointer_to(r) };
    { a.allocate(n) } -> std::same_as<T*>;
    { a.deallocate(p, n) };

    { a == a1 } -> std::same_as<bool>;
    { a != a1 } -> std::same_as<bool>;
};
} // namespace concepts

#ifdef CONCEPTS_TESTING

#include <cstddef>
#include <memory_resource>
#include <string>

static_assert(concepts::Allocator<std::allocator, std::byte>);
static_assert(concepts::Allocator<std::allocator, std::string>);
static_assert(concepts::Allocator<std::pmr::polymorphic_allocator, std::byte>);
static_assert(concepts::Allocator<std::pmr::polymorphic_allocator, std::string>);

#endif
