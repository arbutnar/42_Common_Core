/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Directives.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:44:09 by arbutnar          #+#    #+#             */
/*   Updated: 2023/11/15 15:07:56 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIRECTIVES_HPP
# define DIRECTIVES_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <sstream>
# include <vector>
# include <map>
# include <stdlib.h>
# include <algorithm>

class	Location;

typedef std::vector<std::string> v_Str;
typedef std::map<int,std::string> m_IntStr;
typedef std::map<std::string, bool> m_StrBool;

enum	commonDirectives {
	LISTEN,
	SERVER_NAME,
	ROOT,
	INDEX,
	AUTOINDEX,
	SCGI_PASS,
	TRY_FILES,
	LIMIT_EXCEPT,
	ERROR_PAGE,
	CLIENT_MAX_BODY_SIZE
};

class Directives {
	protected:
		u_int32_t	    _listen_host;	//htonl
		u_int16_t 		_listen_port;	//htons
		std::string     _server_name;
		std::string		_root;
		v_Str			_index;
		bool			_autoindex;
		std::string		_scgi_pass;
		v_Str			_try_files;
		m_StrBool		_limit_except;
		m_IntStr		_error_page;
		unsigned int	_client_max_body_size;
	public:
		struct SyntaxError : public std::exception {
			virtual const char* what() const throw() { return ("Incomplete or wrong configurations Syntax"); }
		};

		Directives( void );
		Directives( const Directives &src );
		Directives& operator=( const Directives &src );
		virtual ~Directives( );

		void	parseListen( const std::string &attribute );
		void	parseListenHost( const std::string &attribute );
		void	parseListenPort( const std::string &attribute );
		void	parseIndex( const std::string &attribute );
		void	parseAutoindex( const std::string &attribute );
		void	parseTryFiles( const std::string &attribute );
		void	parseLimitExcept( const std::string &attribute );
		void	parseErrorPage( const std::string &attribute );
		void	parseClientMaxBodySize( const std::string &attribute );

		void	setListenHost( const u_int32_t &listen_host );
		void	setListenPort( const u_int16_t &listen_port );
		void	setServerName( const std::string &server_name );
		void	setRoot( const std::string &root );
		void	setIndex( const v_Str &index );
		void	setAutoindex( const bool &autoindex );
		void	setScgiPass( const std::string &scgi_pass );
		void	setTryFiles( const v_Str &try_files );
		void	setLimitExcept( const m_StrBool &limit_except );
		void	setErrorPage( const m_IntStr &error_page );
		void	setClientMaxBodySize( const unsigned int &client_max_body_size );

		const u_int32_t&	getListenHost( void ) const ;
		const u_int16_t&	getListenPort( void ) const ;
		const std::string&	getServerName( void ) const ;
		const std::string&	getRoot( void ) const ;
		const v_Str&		getIndex( void ) const ;
		const bool&			getAutoindex( void ) const ;
		const std::string&	getScgiPass( void ) const ;
		const v_Str&		getTryFiles( void ) const ;
		const m_StrBool&	getLimitExcept( void ) const ;
		const m_IntStr&		getErrorPage( void ) const ;
		const unsigned int&	getClientMaxBodySize( void ) const ;

		void			directiveParser( std::string line );
		void			displayDirectives( void ) const;
		virtual void	addLocation( const Location &location );
};

#endif