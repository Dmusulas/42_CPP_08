/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 16:17:48 by dmusulas          #+#    #+#             */
/*   Updated: 2025/11/28 16:56:56 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <stdexcept>

// Default Constructor
Span::Span() : _maxCapacity(0) {}

Span::Span(unsigned int N) : _maxCapacity(N) {}

// Copy Constructor
Span::Span(const Span &other)
    : _maxCapacity(other._maxCapacity), _numbers(other._numbers) {}

// Copy Assignment Operator
Span &Span::operator=(const Span &other) {
    if (this != &other) {
        this->_maxCapacity = other._maxCapacity;
        this->_numbers = other._numbers;
    }
    return *this;
}

// Destructor
Span::~Span() {}

void Span::addNumber(int Number) {
    if (_numbers.size() >= _maxCapacity) {
        throw std::length_error("Span is full");
    }
    _numbers.push_back(Number);
}

unsigned int Span::shortestSpan() {
    if (_numbers.size() < 2) {
        throw std::logic_error("Not enough numbers to find shortest span.");
    }

    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());

    unsigned int minSpan = sorted[1] - sorted[0];

    for (size_t i = 1; i < sorted.size(); i++) {
        unsigned int diff = sorted[i] - sorted[i - 1];
        if (diff < minSpan) {
            minSpan = diff;
        }
    }
    return minSpan;
}

unsigned int Span::longestSpan() {
    if (_numbers.size() < 2) {
        throw std::logic_error("Not enough numbers to find shortest span.");
    }

    std::vector<int>::iterator minIt =
        std::min_element(_numbers.begin(), _numbers.end());
    std::vector<int>::iterator maxIt =
        std::max_element(_numbers.begin(), _numbers.end());

    return *maxIt - *minIt;
}
