/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 16:59:01 by dmusulas          #+#    #+#             */
/*   Updated: 2025/11/29 20:21:01 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cmath>
#include <cstdlib>
#include <ctime>

int main() {
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    // testing with a looooot of numbers
    unsigned int size = 10 * static_cast<unsigned int>(std::pow(10, 6));
    std::cout << "Size of span: " << size << std::endl;

    Span bigspan = Span(size);
    std::vector<int> randomNumbers;
    randomNumbers.reserve(size); // Optimization to prevent reallocations

    std::srand(std::time(NULL));
    for (unsigned int i = 0; i < size; i++) {
        randomNumbers.push_back(std::rand());
    }

    try {
        bigspan.addNumber(randomNumbers.begin(), randomNumbers.end());
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    std::cout << "Shortest Span: " << bigspan.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << bigspan.longestSpan() << std::endl;

    // now make it throw error
    try {
        bigspan.addNumber(1);
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
