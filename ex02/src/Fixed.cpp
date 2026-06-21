/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilnassi <ilnassi@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 02:51:43 by ilnassi           #+#    #+#             */
/*   Updated: 2026/06/21 02:53:38 by ilnassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _fixedRawValue(0) {}

Fixed::Fixed(Fixed const &other) {
    *this = other;
}

Fixed   &Fixed::operator=(Fixed const &other) {
    if (this != &other)
        this->_fixedRawValue = other.getRawBits();
    return (*this);
}

Fixed::~Fixed() {}

Fixed::Fixed(int const intValue) {
    this->_fixedRawValue = intValue << _fractionalBits;
}

Fixed::Fixed(float const floatValue) {
    this->_fixedRawValue = roundf(floatValue * (1 << _fractionalBits));
}

float   Fixed::toFloat(void) const {
    return ((float)this->_fixedRawValue / (1 << _fractionalBits));
}

int     Fixed::toInt(void) const {
    return (this->_fixedRawValue >> _fractionalBits);
}

int     Fixed::getRawBits(void) const {
    return (this->_fixedRawValue);
}

void    Fixed::setRawBits(int const raw) {
    this->_fixedRawValue = raw;
}

// Comparison operators
bool    Fixed::operator>(Fixed const &other) const { return (this->_fixedRawValue > other.getRawBits()); }
bool    Fixed::operator<(Fixed const &other) const { return (this->_fixedRawValue < other.getRawBits()); }
bool    Fixed::operator>=(Fixed const &other) const { return (this->_fixedRawValue >= other.getRawBits()); }
bool    Fixed::operator<=(Fixed const &other) const { return (this->_fixedRawValue <= other.getRawBits()); }
bool    Fixed::operator==(Fixed const &other) const { return (this->_fixedRawValue == other.getRawBits()); }
bool    Fixed::operator!=(Fixed const &other) const { return (this->_fixedRawValue != other.getRawBits()); }

// Arithmetic operators
Fixed   Fixed::operator+(Fixed const &other) const { return (Fixed(this->toFloat() + other.toFloat())); }
Fixed   Fixed::operator-(Fixed const &other) const { return (Fixed(this->toFloat() - other.toFloat())); }
Fixed   Fixed::operator*(Fixed const &other) const { return (Fixed(this->toFloat() * other.toFloat())); }
Fixed   Fixed::operator/(Fixed const &other) const { return (Fixed(this->toFloat() / other.toFloat())); }

// Increment / Decrement
Fixed&  Fixed::operator++(void) { this->_fixedRawValue++; return (*this); }
Fixed   Fixed::operator++(int) { Fixed tmp(*this); this->_fixedRawValue++; return (tmp); }
Fixed&  Fixed::operator--(void) { this->_fixedRawValue--; return (*this); }
Fixed   Fixed::operator--(int) { Fixed tmp(*this); this->_fixedRawValue--; return (tmp); }

// Static functions
Fixed& Fixed::min(Fixed &a, Fixed &b) {
    if (a < b)
        return (a);
    return (b);
}

Fixed const& Fixed::min(Fixed const &a, Fixed const &b) {
    if (a < b)
        return (a);
    return (b);
}

Fixed& Fixed::max(Fixed &a, Fixed &b) {
    if (a > b)
        return (a);
    return (b);
}

Fixed const& Fixed::max(Fixed const &a, Fixed const &b) {
    if (a > b)
        return (a);
    return (b);
}

std::ostream& operator<<(std::ostream &out, Fixed const &fixed) {
    out << fixed.toFloat();
    return (out);
}
