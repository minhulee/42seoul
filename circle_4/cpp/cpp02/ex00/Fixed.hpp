/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:40:02 by minhulee          #+#    #+#             */
/*   Updated: 2024/08/13 12:52:17 by minhulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

class   Fixed
{
    public:
        Fixed(void);
        Fixed(const Fixed &other);
        ~Fixed();
        
        Fixed   &operator=(const Fixed &other);

        void    setRawBits(const int raw);
        int     getRawBits(void) const;

    private:
        int                 value;
        static const int    rawBits = 8;
};
