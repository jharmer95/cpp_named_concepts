#pragma once

#include "LegacyIterator.hpp"
#include "EqualityComparable.hpp"

#include <concepts>
#include <iterator>

namespace concepts
{
template<typename It>
concept LegacyInputIterator = requires(It i, It j)
{
    requires LegacyIterator<It>;
    requires EqualityComparable<It>;

    { i != j } -> std::convertible_to<bool>;
    { *i } -> std::same_as<typename std::iterator_traits<It>::reference>;
    { ++i } -> std::same_as<It&>;
    { *i++ } -> std::convertible_to<typename std::iterator_traits<It>::value_type>;
};
} // namespace concepts
