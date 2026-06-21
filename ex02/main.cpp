/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilnassi <ilnassi@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 02:47:06 by ilnassi           #+#    #+#             */
/*   Updated: 2026/06/21 02:54:19 by ilnassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void ) {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    // Test del soggetto di 42
    std::cout << "--- Test Soggetto ---" << std::endl;
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;

    // Test addizionali per gli operatori rimanenti (Consigliato per la correzione)
    std::cout << "\n--- Test Extra ---" << std::endl;
    Fixed c(2.5f);
    Fixed d(1.5f);
    
    std::cout << "c (" << c << ") + d (" << d << ") = " << (c + d) << std::endl;
    std::cout << "c (" << c << ") - d (" << d << ") = " << (c - d) << std::endl;
    std::cout << "c > d: " << (c > d) << " (1 = True, 0 = False)" << std::endl;
    std::cout << "Fixed::min(c, d): " << Fixed::min(c, d) << std::endl;

    return 0;
}
