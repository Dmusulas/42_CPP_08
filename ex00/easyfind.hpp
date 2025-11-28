/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:37:44 by dmusulas          #+#    #+#             */
/*   Updated: 2025/11/28 16:02:50 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>

// I decided to throw error instead of returning container.end() like STL
// because otherwise it would be just a wrapper for std::find and not so
// EASY to use
template <typename T> typename T::iterator easyfind(T &container, int value) {
    typename T::iterator result =
        std::find(container.begin(), container.end(), value);
    if (result == container.end()) {
        throw std::runtime_error("Value not found");
    }
    return result;
};

#endif // !EASYFIND_HPP
