#pragma once

#include "LegacyInputIterator.hpp"
#include "DefaultConstructible.hpp"
#include "LegacyOutputIterator.hpp"

#include <concepts>
#include <iterator>

namespace concepts
{
template<typename It>
concept LegacyForwardIterator = requires(It i)
{
    requires !LegacyOutputIterator<It>
        || (LegacyOutputIterator<It> && std::same_as<typename std::iterator_traits<It>::value_type&, typename std::iterator_traits<It>::reference>);

    { i++ } -> std::same_as<It>;
    { *i++ } -> std::same_as<typename std::iterator_traits<It>::reference>;
};
} // namespace concepts
