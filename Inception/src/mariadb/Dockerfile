FROM debian:buster

RUN apt-get update -y && apt-get install -y mariadb-server

EXPOSE 3306

COPY ./tools/50-server.cnf /etc/mysql/mariadb.conf.d/
COPY ./tools/initial_db.sql /var/www/

RUN chmod 600 /etc/mysql/mariadb.conf.d/50-server.cnf && service mysql start && mysql < /var/www/initial_db.sql

CMD ["mysqld"]
