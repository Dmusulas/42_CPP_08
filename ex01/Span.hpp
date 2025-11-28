/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 16:31:37 by dmusulas          #+#    #+#             */
/*   Updated: 2025/11/28 17:00:47 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>

class Span {
private:
    unsigned int _maxCapacity;
    std::vector<int> _numbers;

public:
    Span(unsigned int N);
    Span();
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();

    void addNumber(int number);

    template <typename Iterator> void addNumber(Iterator begin, Iterator end) {
        unsigned int dist = std::distance(begin, end);

        if (_numbers.size() + dist > _maxCapacity) {
            throw std::length_error("Span capacity exceeded");
        }

        _numbers.insert(_numbers.end(), begin, end);
    }
    unsigned int shortestSpan();
    unsigned int longestSpan();
};

#endif
