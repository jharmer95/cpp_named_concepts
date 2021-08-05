#pragma once

#include "CopyConstructible.hpp"
#include "CopyAssignable.hpp"
#include "Destructible.hpp"
#include "Swappable.hpp"

#include <concepts>
#include <iterator>

namespace concepts
{
template<typename It>
concept LegacyIterator = requires(It r)
{
    requires CopyConstructible<It>;
    requires CopyAssignable<It>;
    requires Destructible<It>;
    requires Swappable<It>;

    typename std::iterator_traits<It>::value_type;
    typename std::iterator_traits<It>::difference_type;
    typename std::iterator_traits<It>::reference;
    typename std::iterator_traits<It>::pointer;
    typename std::iterator_traits<It>::iterator_category;

    { *r };
    { ++r } -> std::same_as<It&>;
};
} // namespace concepts
