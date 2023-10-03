FROM debian:buster

RUN apt-get -y update \
	&& apt-get -y install mariadb-server

COPY ./50-server.cnf /etc/mysql/mariadb.conf.d/
COPY ./script.sh /

ENTRYPOINT chown mysql:mysql /etc/mysql/mariadb.conf.d/50-server.cnf && chmod 600 /etc/mysql/mariadb.conf.d/50-server.cnf && ./script.sh