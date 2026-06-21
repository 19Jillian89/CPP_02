/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilnassi <ilnassi@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 01:55:24 by ilnassi           #+#    #+#             */
/*   Updated: 2026/06/21 02:18:12 by ilnassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class   Fixed
{
    private:
        int                 _fixedRawValue;
        static const int    _fractionalBits = 8; 
    public:
        Fixed();
        Fixed(const Fixed &other);
        Fixed& operator=(const Fixed &other);
        ~Fixed();

        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif
