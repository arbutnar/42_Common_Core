/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Connection.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:38:10 by arbutnar          #+#    #+#             */
/*   Updated: 2023/12/09 16:14:09 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Connection.hpp"

Connection::Connection( void )
	: _socket (0), _buffer ("") {
}

Connection::Connection( int const &socket )
	: _socket (socket) {
}

Connection::Connection( Connection const &src ) {
	*this = src;
}

Connection	&Connection::operator=( Connection const &src ) {
	if (this == &src)
		return *this;
	_socket = src._socket;
	_buffer = src._buffer;
	return *this;
}

bool	Connection::operator==( Connection const &src ) const {
	if (_socket != src._socket)
		return false;
	return true;
}

Connection::~Connection( void ) {
	std::cout << _socket << " disconnected" << std::endl;
	if (_socket != 0)
		close(_socket);
}

int const	&Connection::getSocket( void ) const {
	return _socket;
}

std::string const	&Connection::getBuffer( void ) const {
	return _buffer;
}

void	Connection::setSocket( int const &socket ) {
	_socket = socket;
}

void	Connection::setBuffer( std::string const &buffer ) {
	_buffer = buffer;
}

bool	Connection::writeRequest( void ) {
	char	c;
	int		nBytes = recv(_socket, &c, 1, 0);
	if (nBytes <= 0)
		return false;
	_buffer += c;
	return true;
}

void	Connection::clearBuffer( void ) {
	_buffer.clear();
}

