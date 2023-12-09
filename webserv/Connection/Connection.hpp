/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Connection.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:38:05 by arbutnar          #+#    #+#             */
/*   Updated: 2023/12/09 12:15:24 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONNECTION_HPP
# define CONNECTION_HPP

# include <iostream>
# include <sys/socket.h>

class Connection {
	private:
		int			_socket;
		std::string	_buffer;
	public:
		Connection( void );
		Connection( int const &socket );
		Connection( Connection const &src );
		Connection	&operator=( Connection const &src );
		bool	operator==( Connection const &src ) const ;
		~Connection();

		int const			&getSocket( void ) const;
		std::string const	&getBuffer( void ) const;
		void				setSocket( int const &socket );
		void				setBuffer( std::string const &buffer );

		bool	writeRequest( void );
		void	clearBuffer( void );
};

#endif