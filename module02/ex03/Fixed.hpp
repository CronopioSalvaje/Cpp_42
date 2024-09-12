/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ls <ls@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 18:35:30 by ls                #+#    #+#             */
/*   Updated: 2024/08/05 15:43:48 by ls               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
    int integer;
    static const int fraction = 8;
public:
    Fixed();
    Fixed(Fixed const &tc);
    Fixed(int integer);
    Fixed(float fl);
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat( void ) const;
    static bool check_overflow( int a, int b, long long int (*oper)(int, int));
    void    store_result(int val);
    int toInt( void ) const;
    static float getMaxFloat(void);
    static int getMaxInt(void);
    static float getMinFloat(void);
    static int getMinInt(void);
    static bool check_min_max(int integer);
    static bool check_min_max(float integer);
    static Fixed min (Fixed &a, Fixed &b);
    static Fixed min (Fixed const &a, Fixed const &b);
    static Fixed max (Fixed &a, Fixed &b);
    static Fixed max (Fixed const &a, Fixed const &b);
    static int get_fraction(void);
    //void operator=(Fixed const &b);
    void operator=(const Fixed &b);
    Fixed &operator++();
    Fixed operator++(int);
    Fixed &operator+=(int val);
    Fixed &operator--();
    Fixed operator--(int);
    Fixed &operator-=(Fixed val);
    Fixed &operator*=(Fixed val);
    Fixed &operator/=(Fixed val);
    Fixed &operator+=(Fixed val);
    ~Fixed();    
};

std::ostream &operator<<(std::ostream &print, Fixed const &nbr);
Fixed operator*(Fixed const &a, Fixed const &b);
Fixed operator*(Fixed const &a, Fixed const &b);
Fixed operator-(Fixed const &a, Fixed const &b);
Fixed operator+(Fixed const &a, Fixed const &b);
Fixed operator/(Fixed const &a, Fixed const &b);
bool operator>(Fixed const &a, Fixed const &b);
bool operator>=(Fixed const &a, Fixed const &b);
bool operator<(Fixed const &a, Fixed const &b);
bool operator<=(Fixed const &a, Fixed const &b);
bool operator!=(Fixed const &a, Fixed const &b);
bool operator==(Fixed const &a, Fixed const &b);

#endif