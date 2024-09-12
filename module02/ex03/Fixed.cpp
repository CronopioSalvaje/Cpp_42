/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ls <ls@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 18:35:00 by ls                #+#    #+#             */
/*   Updated: 2024/08/06 08:38:50 by ls               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "cmath"

Fixed::Fixed()
{
    this->integer = 0;
    //std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &tc)
{
    //std::cout << "Copy constructor called" << std::endl;
    this->integer = tc.getRawBits(); 
}

bool Fixed::check_min_max(int integer)
{
    int max = Fixed::getMaxInt();
    int min = Fixed::getMinInt();    
    if (integer > max || integer < min)
    {
        std::cout << "error : overflow detected" << std::endl;
        return (true);        
    }
    return (false);    
}
float Fixed::getMaxFloat(void)
{
    int offset = 32 - 1 - Fixed::fraction;
    return (static_cast<float>((1 << offset) - 1 + (256.0f / 255.0f)));    
}
int Fixed::getMaxInt(void)
{
    int offset = 32 - 1 - Fixed::fraction;
    return ((1 << offset) - 1);
}
float Fixed::getMinFloat(void)
{
    int offset = 32 - 1 - Fixed::fraction;
    return (static_cast<float>(-(1 << offset)));
}
int Fixed::getMinInt(void)
{
    int offset = 32 - 1 - Fixed::fraction;
    return (-(1 << offset));
}


bool Fixed::check_min_max(float fl)
{
    float max = Fixed::getMaxFloat();
    float min = Fixed::getMinFloat();
    
    if (fl > max || fl < min)
    {
        std::cout << "error : overflow detected" << std::endl;
        return (true);
    }
    return (false);    
}

Fixed::Fixed(int integer) : integer(integer << this->fraction)
{
    if (Fixed::check_min_max(integer))
        std::cout << "result may be inconsistent" << std::endl;
}
Fixed::Fixed(float fl) : integer(static_cast<int>(roundf(fl * (1 << this->fraction))))
{
    if (Fixed::check_min_max(fl))
        std::cout << "result may be inconsistent" << std::endl;
}

long long int add(int a, int b)
{
    return a + b;
}

long long int substract(int a, int b)
{
    return a - b;
}

long long int multiply(int a, int b)
{
    return a * b / (1 << Fixed::get_fraction());
}

long long int divide(int a, int b)
{
    return ((a << Fixed::get_fraction())/ b) ;
}

bool Fixed::check_overflow(int a, int b, long long int (*oper)(int, int))
{
    int fixedMax = Fixed::getMaxInt();
    int fixedMin = Fixed::getMinInt();
    //std::cout << "fixedMax : " << fixedMax <<" - fixedMin : " << fixedMin << std::endl;
    //std::cout << "a : " << a <<" - b : " << b << std::endl;
    long long int result = oper(a, b);
    //std::cout << "result : " << result << std::endl;
    if ((result > fixedMax || result < fixedMin) /*|| (a > 0 && b > 0 && result < 0)*/)
    {
        std::cout << "error : overflow detected" << std::endl;
        return (true);
    }
    return (false);
}

Fixed::~Fixed()
{
}

int Fixed::get_fraction(void)
{
    return fraction;
}

float Fixed::toFloat( void ) const
{
    return static_cast<float>(this->integer) / (1 << this->fraction);
}

int Fixed::toInt( void ) const
{
    return (int)this->integer >> this->fraction;
}

int Fixed::getRawBits(void) const
{
    return this->integer;
}

void Fixed::setRawBits( int const raw )
{  
    this->integer = raw << this->fraction;
}

Fixed Fixed::min (Fixed const &a, Fixed const &b)
{
    return (a < b) ? a : b;    
}

Fixed Fixed::min (Fixed &a, Fixed &b)
{
    return (a < b) ? a : b;   
}
Fixed Fixed::max(Fixed const &a, Fixed const &b)
{
    return (a > b) ? a : b;
}

Fixed Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b) ? a : b;
}

/**
 * operators
*/

std::ostream &operator<<(std::ostream &print, Fixed const &nbr)
{
    return print << nbr.toFloat();
}

void Fixed::store_result(int val)
{
    this->integer = val;
}

Fixed operator*(Fixed const &a, Fixed const &b)
{

    Fixed result;
    Fixed::check_overflow(a.getRawBits(), b.getRawBits(), multiply);
    int raw = (a.getRawBits() * b.getRawBits()) / (1 << result.get_fraction());
    result.store_result(raw);
    return result;
}

Fixed operator-(Fixed const &a, Fixed const &b)
{
    Fixed result;
    Fixed::check_overflow(a.getRawBits(), b.getRawBits(), substract);
    result.store_result((a.getRawBits() - b.getRawBits()));
    return result;
}

Fixed operator+(Fixed const &a, Fixed const &b)
{
    Fixed result;
    Fixed::check_overflow(a.getRawBits(), b.getRawBits(), add);
    result.store_result((a.getRawBits() + b.getRawBits()));
    return result;
}

Fixed operator/(Fixed const &a, Fixed const &b)
{
    Fixed result;
    if (b.getRawBits() == 0)
    {
        std::cout << "error : division by zero" << std::endl;
        return a;
    }
    Fixed::check_overflow(a.getRawBits(), b.getRawBits(), divide);
    result.store_result(((a.getRawBits() << result.get_fraction()) / b.getRawBits()));
    return result;
}

bool operator>(Fixed const &a, Fixed const &b)
{
    return a.getRawBits() > b.getRawBits();
}
bool operator>=(Fixed const &a, Fixed const &b)
{
    return a.getRawBits() >= b.getRawBits();
}
bool operator<(Fixed const &a, Fixed const &b)
{
    return a.getRawBits() < b.getRawBits();
}
bool operator<=(Fixed const &a, Fixed const &b)
{
    return a.getRawBits() <= b.getRawBits();
}
bool operator!=(Fixed const &a, Fixed const &b)
{
    return a.getRawBits() != b.getRawBits();
}
bool operator==(Fixed const &a, Fixed const &b)
{
    return a.getRawBits() == b.getRawBits();
}

    /*void Fixed::operator=(Fixed const &b)
    {        
        this->integer = b.getRawBits();
    }*/

    void Fixed::operator=(const Fixed &b)
    {        
        this->integer = b.getRawBits();
    }
    
    Fixed &Fixed::operator++()
    {
        ++this->integer;
        return *this;
    }
    Fixed Fixed::operator++(int)
    {
        Fixed temp = *this;
        ++this->integer;
        return temp; 
    }
    Fixed &Fixed::operator+=(Fixed val)
    {
        int result;
        
        Fixed::check_overflow(this->getRawBits(), val.getRawBits(), add);
        result = (this->getRawBits() + val.getRawBits());
        this->store_result(result);
        return *this;
    }
    Fixed &Fixed::operator--()
    {
        --this->integer;
        return *this;
    }
    Fixed Fixed::operator--(int)
    {
        Fixed temp = *this;
        --this->integer;
        return temp; 
    }
    Fixed &Fixed::operator-=(Fixed val)
    {
        int result;
        
        Fixed::check_overflow(this->getRawBits(), val.getRawBits(), substract);
        result = (this->getRawBits() - val.getRawBits());
        this->store_result(result);
        return *this;
    }
    Fixed &Fixed::operator*=(Fixed val)
    {
        int result;

        Fixed::check_overflow(this->getRawBits(), val.getRawBits(), multiply);
        //std::cout << 
        result = (this->getRawBits() * val.getRawBits()) / (1 << this->get_fraction());
        this->store_result(result);
        return *this;
    }
    Fixed &Fixed::operator/=(Fixed val)
    {
        long long int result;
        if (val.getRawBits() == 0)
        {
            std::cout << "error : division by zero" << std::endl;
            return *this;
        }
        Fixed::check_overflow(this->getRawBits(), val.getRawBits(), divide);
        result = (this->getRawBits() / val.getRawBits()) << this->get_fraction();
        this->store_result(static_cast<int>(result));
        return *this;
    }
    