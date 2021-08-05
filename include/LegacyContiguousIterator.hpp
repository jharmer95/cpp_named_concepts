#pragma once

#include "LegacyIterator.hpp"

#include <concepts>
#include <cstddef>
#include <iterator>

namespace concepts
{
template<typename It>
concept LegacyContiguousIterator = requires(It a, std::ptrdiff_t n)
{
    requires LegacyIterator<It>;

    { a + n } -> std::same_as<It>;
    { *(a + n) } -> std::same_as<typename std::iterator_traits<It>::reference>;
};
} // namespace concepts
