#pragma once

#include "EqualityComparable.hpp"
#include "DefaultConstructible.hpp"
#include "CopyConstructible.hpp"
#include "CopyAssignable.hpp"
#include "Destructible.hpp"

#include <cstddef>
#include <type_traits>

namespace concepts
{
template<typename T>
concept NullablePointer = requires(T p, T q, std::nullptr_t np)
{
    requires EqualityComparable<T>;
    requires DefaultConstructible<T>;
    requires CopyConstructible<T>;
    requires CopyAssignable<T>;
    requires Destructible<T>;

    { p = np } -> std::same_as<T&>;
    { p != q } -> std::convertible_to<bool>;
    { p == np } -> std::convertible_to<bool>;
    { np == p } -> std::convertible_to<bool>;
    { p != np } -> std::convertible_to<bool>;
    { np != p } -> std::convertible_to<bool>;
};
} // namespace concepts

#ifdef CONCEPTS_TESTING

#include <exception>
#include <memory>
#include <optional>

static_assert(!concepts::NullablePointer<std::optional<int>>);
static_assert(concepts::NullablePointer<int*>);
static_assert(concepts::NullablePointer<typename std::unique_ptr<int>::pointer>);
static_assert(concepts::NullablePointer<std::exception_ptr>);

#endif
