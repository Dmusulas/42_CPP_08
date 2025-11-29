/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 20:03:27 by dmusulas          #+#    #+#             */
/*   Updated: 2025/11/29 20:31:09 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <exception>
#include <iostream>
#include <list>
#include <stack>

template <class T> class MutantStack : public std::stack<T> {
private:
public:
    MutantStack() : std::stack<T>(){};
    MutantStack(const MutantStack &other) : std::stack<T>(other){};
    MutantStack &operator=(const MutantStack &other) {
        if (this != &other) {
            std::stack<T>::operator=(other);
        }
        return *this;
    };
    ~MutantStack(){};

    typedef typename std::stack<T>::container_type::iterator iterator;

    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }

    typedef
        typename std::stack<T>::container_type::const_iterator const_iterator;

    const_iterator begin() const { return this->c.begin(); }
    const_iterator end() const { return this->c.end(); }

    typedef typename std::stack<T>::container_type::reverse_iterator
        reverse_iterator;

    reverse_iterator rbegin() { return this->c.rbegin(); }
    reverse_iterator rend() { return this->c.rend(); }

    typedef typename std::stack<T>::container_type::const_reverse_iterator
        const_reverse_iterator;

    const_reverse_iterator rbegin() const { return this->c.rbegin(); }
    const_reverse_iterator rend() const { return this->c.rend(); }
};

#endif
