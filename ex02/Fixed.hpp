/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2022/01/25 12:11:31 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	public:
		Fixed(void);
		Fixed(Fixed const & src);
		Fixed(int const n);
		Fixed(float const f);
		~Fixed(void);

		Fixed & operator=(Fixed const & src);

		int getRawBits( void ) const;
		void setRawBits( int const raw );

		float toFloat( void ) const;
		int toInt( void ) const;

		bool	operator<(Fixed const fixed) const;
		bool	operator>(Fixed const fixed) const;
		bool	operator<=(Fixed const fixed) const;
		bool	operator>=(Fixed const fixed) const;
		bool	operator==(Fixed const fixed) const;
		bool	operator!=(Fixed const fixed) const;

		Fixed	operator+(Fixed const fixed);
		Fixed	operator-(Fixed const fixed);
		Fixed	operator*(Fixed const fixed);
		Fixed	operator/(Fixed const fixed);

		Fixed	operator++(void);
		Fixed	operator--(void);
		Fixed	operator++(int);
		Fixed	operator--(int);

		static Fixed & max(Fixed & fixed1, Fixed & fixed2);
		static const Fixed &max(Fixed const & fixed1, Fixed const & fixed2);
		static Fixed & min(Fixed & fixed1, Fixed & fixed2);
		static const Fixed &min(Fixed const & fixed1, Fixed const & fixed2);

	private:
		int			_n;    
		int const	_nBits;

};

std::ostream &operator<<(std::ostream & o, Fixed const &point);

#endif