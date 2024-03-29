/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:39:33 by arbutnar          #+#    #+#             */
/*   Updated: 2023/09/14 15:56:24 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int	main()
{
	std::cout << "--Testing with MUTANTSTACK--" << std::endl << std::endl;
	MutantStack<int>	mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << "last inserted in stack: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "size of stack: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << "--Testing with LIST--" << std::endl << std::endl;
	std::list<int>	test;

	test.push_front(5);
	test.push_front(17);
	std::cout << "last inserted in stack: " << test.front() << std::endl;
	test.pop_front();
	std::cout << "size of stack: " << test.size() << std::endl;
	test.push_back(3);
	test.push_back(5);
	test.push_back(737);
	//[...]
	test.push_back(0);
	std::list<int>::iterator it2 = test.begin();
	std::list<int>::iterator ite2 = test.end();
	++it2;
	--it2;
	while (it2 != ite2) {
		std::cout << *it2 << std::endl;
		++it2;
	}
	std::list<int> s2(test);

	return 0;
}
