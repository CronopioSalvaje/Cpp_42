/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:07:41 by calbor-p          #+#    #+#             */
/*   Updated: 2024/12/05 20:12:29 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdint.h>

class Data
{
	private:
		static int instance;
		int id;

	public:
		Data();
		Data(Data const &cl);
		int getId();
		Data &operator=(Data const &cl);
		~Data();
};

