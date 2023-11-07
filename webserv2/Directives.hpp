/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Directives.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:08:13 by arbutnar          #+#    #+#             */
/*   Updated: 2023/11/07 17:18:59 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>

class Directives {
	private:
		class FileError;

		unsigned int    _listen;
		std::string     _server_name;
		std::string		_root;
		std::string		_index;
		std::string		_autoindex;
		std::string		_scgi_pass;
		const char*		_try_files;
		const char*		_limit_except;
		const char*		_error_page;
		unsigned int	_client_max_body_size;
	public:
		Directive( void );
		Directive( const char* configPath );
		Directive( const Directive &src );
		Directive& operator=( Directive &src ); //const
		~Directive( );
	
		// void	setListen( std::string confLine );
		// void	setServerName( std::string confLine );
		// void	setRoot( std::string confLine );
		// void	setIndex( std::string confLine );
		// void	setAutoindex( std::string confLine );
		// void	setScgiPass( std::string confLine );
		// void	setTryFiles( std::string confLine );
		// void	setLimitExcept( std::string confLine );
		// void	setErrorPage( std::string confLine );
		// void	setClientMaxBodySize( std::string confLine );
};
