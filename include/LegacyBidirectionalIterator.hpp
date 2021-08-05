#pragma once

#include "LegacyForwardIterator.hpp"

#include <concepts>
#include <iterator>

namespace concepts
{
template<typename It>
concept LegacyBidirectionalIterator = requires(It a)
{
    requires LegacyForwardIterator<It>;

    { --a } -> std::same_as<It&>;
    { a-- } -> std::convertible_to<const It&>;
    { *a-- } -> std::same_as<typename std::iterator_traits<It>::reference>;
};
} // namespace concepts
