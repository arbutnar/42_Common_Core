/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:24:46 by arbutnar          #+#    #+#             */
/*   Updated: 2023/12/09 16:16:09 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

Server::Server( void ) {
}

Server::Server( std::string block ) {
    std::cout << block << std::endl;
}

Server::Server( const Server &src )
	: Directives(src) {
		*this = src;
}

Server& Server::operator=( const Server &src ) {
    if (this == &src)
        return *this;
    _locations = src._locations;
	_connections = src._connections;
	_listener = src._listener;
    Directives::operator=(src);
    return *this;
}

bool	Server::operator<( const Server &src ) {
	if (_listen_port != src._listen_port)
		return _listen_port < src._listen_port;
	if (_server_name.compare(src._server_name) < 0)
		return true;
	return false;
}

Server::~Server() {
}

void    Server::setLocations( const s_locs &locations ) {
    _locations = locations;
}

void	Server::setListener( const int &listener ) {
	_listener = listener;
}

void	Server::setConnections( const v_con &connections ) {
	_connections = connections;
}

const s_locs	&Server::getLocations( void ) const {
    return _locations;
}

const int &Server::getListener( void ) const {
	return _listener;
}

const v_con	&Server::getConnections( void ) const {
	return _connections;
}

void    Server::addLocation( const Location &location ) {
	if (_locations.insert(location).second == false)
		throw Directives::SyntaxError();
}

s_locs::const_iterator	Server::findRoot( void ) const {
	for (s_locs::const_iterator it = _locations.begin(); it != _locations.end(); it++)
		if (it->getLocationName() == "/")
			return it;
	return _locations.end();
}

int	Server::nfds( void ) const {
	int temp = 0;

	for (v_con::const_iterator it = _connections.begin(); it != _connections.end(); it++)
		if (temp < it->getSocket())
			temp = it->getSocket();
	return temp;
}

void	Server::ListenerInit( void ) {
	_listener = socket(AF_INET, SOCK_STREAM, 0);
	if (_listener == -1)
		throw std::runtime_error("Cannot create socket");
	const int enable = 1;
	if (setsockopt(_listener, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0)
		throw std::runtime_error("setsockopt(SO_REUSEADDR) failed");
	struct sockaddr_in	sockaddr;
	sockaddr.sin_family = AF_INET;
	sockaddr.sin_port = htons(_listen_port);
	sockaddr.sin_addr.s_addr = htonl(_listen_host);
	if (bind(_listener, (struct sockaddr *)&sockaddr, sizeof(sockaddr)) == -1)
		throw std::runtime_error("Cannot bind socket");
	if (listen(_listener, 10) == -1)
		throw std::runtime_error("Socket cannot Listen");
}

void	Server::newConnection( void ) {
	int newFd = accept(_listener, NULL, NULL);
	if (newFd == -1)
		throw std::runtime_error("Cannot create Client socket");
	_connections.push_back(newFd);
	std::cout << "ciao " << newFd << std::endl;
}

void	Server::manageConnections( const fd_set &read ) {

	v_con::iterator cIt = _Connections.begin();
	while ( cIt != _Connections.end() )
	{
		if (FD_ISSET(cIt->getSocket(), &read) && readRequest(cIt))
			cIt = _connections.erase(cIt);
		else if (cIt->isReady() && sendResponse(cIt))
			cIt = _connections.erase(cIt);
		else
			it++;
	}
}

bool	Server::readRequest( v_con::iterator &connection ) {

	char	c;

	if (recv(connection->getSocket(), &c, 1, 0) <= 0)
		return true;
	if (_buffer.size() == client_header_buffer_size)
		
	_buffer += c;
	return false;
}

bool	Server::interact( v_con::iterator &cIt ) {

	Response	*response = NULL;
	bool		ret = false;
	char		c;
	int			nBytes;

	try {
		nBytes = recv(cIt->getSocket(), &c, 1, 0)
		if(nBytes <= 0)
			return true;
		if (requestStatus)
	}
	catch {
		response = new Error(e.what());
	}
	if (respone != NULL)
	{
		response->send(cIt->getSocket());
		if (respone.getHeaders().at("Connection") == "close")
			ret = true;
		delete response;
	}
	return ret;
	// Request 	request;
	// Response	*response = NULL;
	// bool		ret = true;

	// try {
	// 	std::cout << cIt->getBuffer() << std::endl;
	// 	bufferChecker(cIt->getBuffer());
	// 	request.headersParser(cIt->getBuffer());
	// 	request.headersChecker();
	// 	request.uriMatcher(_locations);
	// 	request.matchChecker();
	// 	request.translateUri();
	// 	request.bodyParser(cIt->getSocket());
	// 	response = new Valid(request);
	// } catch(std::exception &e) {
	// 	response = new Error(e.what());
	// }
	// response->generateBody();
	// response->generateHeaders(request);
	// response->send(cIt->getSocket());
	// if (response->getHeaders().at("Connection") == "close")
	// 	ret = false;
	// cIt->clearBuffer();
	// delete response;
	// return ret;
}

// void	Server::bufferChecker( const std::string &buffer ) const {
// 	std::stringstream	ss(buffer);
// 	std::string			line;

// 	std::getline(ss, line);
// 	if (line.find_first_of(" ") == std::string::npos)
// 		throw std::runtime_error("400");
// 	if (line.length() > _client_header_buffer_size)
// 		throw std::runtime_error("414");
// 	if (ss.str().length() - line.length() > _client_header_buffer_size)
// 		throw std::runtime_error("494");
// }

// v_cli::iterator	Server::eraseClient( v_cli::iterator &c_it ) {
// 	std::cout << c_it->getSocket() << " is disconnected" << std::endl;
// 	close(c_it->getSocket());
// 	return _clients.erase(c_it);
// }

void	Server::displayServer( void ) const {
	std::cout << "Server {" << std::endl;
	displayDirectives();
	for (s_locs::const_iterator it = _locations.begin(); it != _locations.end(); it++)
		it->displayLocation();
	std::cout << "}" << std::endl;
}
