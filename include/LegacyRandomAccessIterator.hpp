#pragma once

#include "LegacyBidirectionalIterator.hpp"

#include <concepts>
#include <iterator>

namespace concepts
{
template<typename It>
concept LegacyRandomAccessIterator = requires(It i, It a, It b, It& r, typename std::iterator_traits<It>::difference_type n)
{
    requires LegacyBidirectionalIterator<It>;

    { r += n } -> std::same_as<It&>;
    { a + n } -> std::same_as<It>;
    { n + a } -> std::same_as<It>;
    { r -= n } -> std::same_as<It&>;
    { i - n } -> std::same_as<It>;
    { b - a } -> std::same_as<typename std::iterator_traits<It>::difference_type>;
    { i[n] } -> std::convertible_to<typename std::iterator_traits<It>::reference>;
    { a < b } -> std::convertible_to<bool>;
    { a > b } -> std::convertible_to<bool>;
    { a >= b } -> std::convertible_to<bool>;
    { a <= b } -> std::convertible_to<bool>;
};
} // namespace concepts
