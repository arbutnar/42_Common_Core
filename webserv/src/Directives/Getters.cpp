/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Getters.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:41:35 by arbutnar          #+#    #+#             */
/*   Updated: 2023/12/06 14:41:35 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Directives.hpp"

const u_int32_t	&Directives::getListenHost( void ) const {
    return _listen_host;
}

const u_int16_t	&Directives::getListenPort( void ) const {
    return _listen_port;
}

const std::string	&Directives::getServerName( void ) const {
	return _server_name;
}

const std::string	&Directives::getRoot( void ) const {
	return _root;
}

const std::string	&Directives::getAlias( void ) const {
	return _alias;
}

const v_str	&Directives::getIndex( void ) const {
	return _index;
}

const bool	&Directives::getAutoindex( void ) const {
	return _autoindex;
}

const std::string	&Directives::getCgiAlias( void ) const {
	return _cgi_alias;
}

const m_strBool	&Directives::getLimitExcept( void ) const {
    return _limit_except;
}

const m_intStr	&Directives::getErrorPage( void ) const {
	return _error_page;
}

const unsigned int	&Directives::getClientMaxBodySize( void ) const {
	return _client_max_body_size;
}

const unsigned int	&Directives::getClientHeaderBufferSize( void ) const {
	return _client_header_buffer_size;
}

const p_intStr	&Directives::getReturn( void ) const {
	return _return;
}
