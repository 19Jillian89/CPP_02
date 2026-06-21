/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilnassi <ilnassi@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 02:37:21 by ilnassi           #+#    #+#             */
/*   Updated: 2026/06/21 02:37:28 by ilnassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _fixedRawValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) : _fixedRawValue(other._fixedRawValue)
{
    std::cout << "Copy Constructor called" << std::endl;
}

// costruttore da int: "entra" un valore reale, lo moltiplico per 2^_fractionalBits
// per ottenere il raw value da memorizzare (vedi schema pizza/fettine)
Fixed::Fixed(const int n)
{
    std::cout << "Int constructor called" << std::endl;
    this->_fixedRawValue = n << _fractionalBits;
}

// costruttore da float: stessa idea, ma serve roundf perché n * 256
// può dare un risultato con decimali, e _fixedRawValue è int
Fixed::Fixed(const float n)
{
    std::cout << "Float constructor called" << std::endl;
    this->_fixedRawValue = roundf(n * (1 << _fractionalBits));
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_fixedRawValue = other.getRawBits();
    return (*this);
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_fixedRawValue);
}

void Fixed::setRawBits(int const raw)
{
    this->_fixedRawValue = raw;
}

// "esco" dal fixed-point: divido per 2^_fractionalBits per tornare al valore reale
// cast a float prima della divisione, altrimenti int/int tronca e perdo i decimali
float Fixed::toFloat(void) const
{
    return (this->_fixedRawValue / (float)(1 << _fractionalBits));
}

// qui invece il risultato finale è int comunque, quindi la divisione intera
// diretta va bene (la parte decimale si perderebbe comunque alla fine)
int Fixed::toInt(void) const
{
    return (this->_fixedRawValue / (1 << _fractionalBits));
}

// operator<< stampa il valore "vero" (float), non il raw value
std::ostream& operator<<(std::ostream &out, const Fixed &n)
{
    out << n.toFloat();
    return (out);
}
