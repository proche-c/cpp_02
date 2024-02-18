/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2022/01/25 12:11:31 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

int	powerOf2(int n)
{
	int	result = 1;

	while (n > 0)
	{
		result = 2 * result;
		n--;
	}
	return result;
}

Fixed::Fixed(void):_n(0), _nBits(8)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(Fixed const & src):_nBits(8)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

Fixed::Fixed(int const n): _nBits(8)
{
	std::cout << "Int constructor called" << std::endl;
	this->_n = n * (1 << this->_nBits);
	return ;
}

Fixed::Fixed(float const f):_nBits(8)
{
	std::cout << "Float constructor called" << std::endl;
	this->_n = roundf(f * (1 << this->_nBits));
	return ;
}

Fixed::~Fixed(void)
{
	std::cout <<"Destructor called" << std::endl;
	return ;
}

Fixed & Fixed::operator=(Fixed const & src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
	{
		this->_n = src.getRawBits();
	}
	return *this;
}

int Fixed::getRawBits( void ) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return this->_n;
}

void Fixed::setRawBits( int const raw )
{
	this->_n = raw;
	return ;
}

float Fixed::toFloat( void ) const
{
	return (float)this->_n / (1 << this->_nBits);
}

int Fixed::toInt( void ) const
{
	return this->_n / (1 << this->_nBits);
}

std::ostream &operator<<(std::ostream & o, Fixed const &point)
{
	o << point.toFloat();
	return o;
}
