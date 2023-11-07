/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Directives.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:17:24 by arbutnar          #+#    #+#             */
/*   Updated: 2023/11/07 17:24:31 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Directives.hpp"

class Directives::FileError : public std::exception {
	public:
		virtual const char* what() const throw() { return ("File Error"); }
};

Directives::Directives( void )
	: _configFile (NULL) {
}

Directives::Directives( const char* path )
	: _configFile (path) {
		if (!(_configFile.is_open()))
			throw Directives::FileError();
        readConfig(path);
		// configParse();
}

Directives::Directives( const Directives &src ) {
	(void)src;
}

Directives& Directives::operator=( Directives &src ) { // const
	return src;
}

Directives::~Directives() {
}

void    configRead( const char* path ) {
    
}
