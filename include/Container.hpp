#pragma once

#include "details/same_as_either.hpp"
#include "CopyInsertable.hpp"
#include "Erasable.hpp"

#include <concepts>
#include <memory>

namespace concepts
{
template<typename C>
concept Container = requires(C a, C b, C&& rv)
{
    requires DefaultConstructible<C>;
    requires CopyConstructible<C>;
    requires EqualityComparable<C>;
    requires Swappable<C>;

    requires CopyInsertable<typename C::value_type, std::allocator<typename C::value_type>>;
    requires EqualityComparable<typename C::value_type>;
    requires Destructible<typename C::value_type>;
    requires Erasable<typename C::value_type, std::allocator<typename C::value_type>>;

    typename C::reference;
    typename C::const_reference;
    typename C::const_iterator;
    requires LegacyForwardIterator<typename C::iterator> && std::convertible_to<typename C::iterator, typename C::const_iterator>;
    requires std::signed_integral<typename C::difference_type>;
    requires std::unsigned_integral<typename C::size_type>;

    { C() } -> std::same_as<C>;
    { C(a) } -> std::same_as<C>;
    { C(rv) } -> std::same_as<C>;
    { a = b } -> std::same_as<C&>;
    { a = rv } -> std::same_as<C>;
    { a.~C() } -> std::same_as<void>;
    { a.begin() } -> details::same_as_either<typename C::iterator, typename C::const_iterator>;
    { a.end() } -> details::same_as_either<typename C::iterator, typename C::const_iterator>;
    { a.cbegin() } -> std::same_as<typename C::const_iterator>;
    { a.cend() } -> std::same_as<typename C::const_iterator>;
    { a == b } -> std::convertible_to<bool>;
    { a != b } -> std::convertible_to<bool>;
    { a.swap(b) } -> std::same_as<void>;
    { swap(a, b) } -> std::same_as<void>;
    { a.size() } -> std::same_as<typename C::size_type>;
    { a.max_size() } -> std::same_as<typename C::size_type>;
    { a.empty() } -> std::convertible_to<bool>;
};
} // namespace concepts

#ifdef CONCEPTS_TESTING

#include <string>
#include <vector>

static_assert(concepts::Container<std::string>);
static_assert(concepts::Container<std::vector<int>>);
static_assert(concepts::Container<std::vector<std::string>>);

#endif
