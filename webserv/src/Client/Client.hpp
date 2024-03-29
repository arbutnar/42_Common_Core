/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:44:39 by marvin            #+#    #+#             */
/*   Updated: 2024/01/07 18:44:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_HPP
# define CLIENT_HPP

# include "../Request/Request.hpp"
# include <fcntl.h>
# include <sys/signal.h>
# include <signal.h>
# include <string.h>

class Client {
	private:
		int			_socket;
		std::string	_buffer;
		int			_cgiPid;
		int			_cgiFd;
	public:
		Client( void );
		Client( const int &socket );
		Client( const Client &src );
		Client &operator=( const Client &src );
		~Client();

		const int			&getSocket( void ) const;
		const std::string	&getBuffer( void ) const;
		const int			&getCgiPid( void ) const;
		const int			&getCgiFd( void ) const;
		void				setSocket( const int &socket );
		void				setBuffer( const std::string &buffer );
		void				setCgiPid( const int &cgiPid );
		void				setCgiFd( const int &cgiFd );

		bool	buildBuffer( const int &socket );
		void	handleCgi( Request &request );
};

#endif
