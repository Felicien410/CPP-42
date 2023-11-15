/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:47:21 by feliciencat       #+#    #+#             */
/*   Updated: 2023/11/15 12:49:06 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Mutanstack.hpp"
#include <string.h>

int main() 
{ 
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(3);
    mstack.push(17);
    std::cout << "top: "<<mstack.top() << std::endl;
    mstack.pop();
    std::cout << "top: "<<mstack.top() << std::endl;
    std::cout << "size: "<<mstack.size() << std::endl; 
    mstack.push(3); 
    mstack.push(5); 
    mstack.push(737); 
    mstack.push(0);
    
    MutantStack<int>::iterator it=mstack.begin(); 
    MutantStack<int>::iterator ite=mstack.end();
    
    std::cout <<std::endl;
    std::cout << "it incrementation and decrementation: "<<std::endl;
    ++it;
    std::cout << *it << std::endl;
    --it;
    std::cout << *it << std::endl;
    std::cout<<std::endl;
    std::cout << "stack: "<<std::endl;
    while(it!=ite) 
    {
        std::cout<<*it<<std::endl; ++it;
    }
    mstack.printStack();

    std::cout<<std::endl;
    std::cout << "new stack: "<<std::endl;
    std::stack<int>s(mstack);
    s.push(42);
    std::cout << "top: "<<s.top() << std::endl;
    return 0; 
}