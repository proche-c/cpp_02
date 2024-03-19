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

Fixed::Fixed(void):_n(0), _nBits(8)
{
	//std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(Fixed const & src):_nBits(8)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

Fixed::Fixed(int const n): _nBits(8)
{
	//std::cout << "Int constructor called" << std::endl;
	this->_n = n * (1 << this->_nBits);
	return ;
}

Fixed::Fixed(float const f):_nBits(8)
{
	//std::cout << "Float constructor called" << std::endl;
	this->_n = roundf(f * (1 << this->_nBits));
	return ;
}

Fixed::~Fixed(void)
{
	//std::cout <<"Destructor called" << std::endl;
	return ;
}

Fixed & Fixed::operator=(Fixed const & src)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
	{
		this->_n = src.getRawBits();
	}
	return *this;
}

int Fixed::getRawBits( void ) const
{
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

bool	Fixed::operator<(Fixed const fixed) const
{
	if (this->toFloat() < fixed.toFloat())
		return 1;
	return 0;
}

bool	Fixed::operator>(Fixed const fixed) const
{
	if (this->toFloat() > fixed.toFloat())
		return 1;
	return 0;
}

bool	Fixed::operator<=(Fixed const fixed) const
{
	if (this->toFloat() <= fixed.toFloat())
		return 1;
	return 0;
}

bool	Fixed::operator>=(Fixed const fixed) const
{
	if (this->toFloat() >= fixed.toFloat())
		return 1;
	return 0;
}

bool	Fixed::operator==(Fixed const fixed) const
{
	if (this->toFloat() == fixed.toFloat())
		return 1;
	return 0;
}

bool	Fixed::operator!=(Fixed const fixed) const
{
	if (this->toFloat() != fixed.toFloat())
		return 1;
	return 0;
}

Fixed	Fixed::operator+(Fixed const fixed)
{
	Fixed	result(this->toFloat() + fixed.toFloat());
	return result;
}

Fixed	Fixed::operator-(Fixed const fixed)
{
	Fixed	result(this->toFloat() - fixed.toFloat());
	return result;
}

Fixed	Fixed::operator*(Fixed const fixed)
{
	Fixed	result(this->toFloat() * fixed.toFloat());
	return result;
}

Fixed	Fixed::operator/(Fixed const fixed)
{
	Fixed	result(this->toFloat() / fixed.toFloat());
	return result;
}

Fixed	Fixed::operator++(int)
{
	Fixed result(*this);
	operator++();
	return (result);
}

Fixed	Fixed::operator++(void)
{
	int	aux = this->getRawBits();
	this->_n = aux + 1;
	return *this;
}

Fixed	Fixed::operator--(void)
{
	int	aux = this->getRawBits();
	this->_n = aux - 1;
	return *this;
}


Fixed	Fixed::operator--(int)
{
	Fixed result(*this);
	operator--();
	return (result);
}

Fixed & Fixed::max(Fixed & fixed1, Fixed & fixed2)
{
	if (fixed1 > fixed2)
		return fixed1;
	return fixed2;
}

const Fixed & Fixed::max(Fixed const & fixed1, Fixed const & fixed2)
{
	if (fixed1.getRawBits() > fixed2.getRawBits())
		return fixed1;
	return fixed2;
}

Fixed & Fixed::min(Fixed & fixed1, Fixed & fixed2)
{
	if (fixed1 > fixed2)
		return fixed1;
	return fixed2;
}

const Fixed & Fixed::min(Fixed const & fixed1, Fixed const & fixed2)
{
	if (fixed1 > fixed2)
		return fixed1;
	return fixed2;
}
