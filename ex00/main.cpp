/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:55:49 by dmusulas          #+#    #+#             */
/*   Updated: 2025/11/28 15:58:53 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <list>
#include <vector>

int main() {

    std::cout << "--- Testing std::vector<int> ---" << std::endl;

    std::vector<int> vec;
    for (int i = 0; i < 10; i++) {
        vec.push_back(i * 2);
    }

    try {
        std::cout << "Searching for 18 in vector... ";
        std::vector<int>::iterator it = easyfind(vec, 18);
        std::cout << "Found value: " << *it << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        std::cout << "Searching for 99 in vector... ";
        std::vector<int>::iterator it = easyfind(vec, 42);
        std::cout << "Found value: " << *it << std::endl;
    } catch (std::exception &e) {
        std::cerr << "[Caught Exception] " << e.what() << std::endl;
    }

    std::cout << std::endl;

    std::cout << "--- Testing std::list<int> ---" << std::endl;
    std::list<int> lst;
    lst.push_back(50);
    lst.push_back(100);
    lst.push_back(150);

    try {
        std::cout << "Searching for 100 in list... ";
        std::list<int>::iterator it = easyfind(lst, 100);
        std::cout << "Found value: " << *it << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        std::cout << "Searching for 404 in list... ";
        std::list<int>::iterator it = easyfind(lst, 404);
        std::cout << "Found value: " << *it << std::endl;
    } catch (std::exception &e) {
        std::cerr << "[Caught Exception] " << e.what() << std::endl;
    }

    return 0;
}
