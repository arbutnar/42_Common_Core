FROM debian:buster

RUN apt update -y
RUN apt upgrade -y
RUN apt install -y php7.3
RUN apt install php-mysqli -y
RUN apt install php-fpm -y
RUN apt install wget -y
RUN apt install curl -y
RUN apt install mariadb-client -y

RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
  && chmod +x wp-cli.phar \
  && mv wp-cli.phar /usr/local/bin/wp

COPY tools/www.conf /etc/php/7.3/fpm/pool.d

RUN mkdir -p /run/php
RUN touch /run/php/php7.3-fpm.pid
WORKDIR /var/www/html/
RUN chown -R www-data /var/www/html
RUN chmod -R 775 /var/www/html
COPY tools/script.sh /usr/local/bin/

#RUN mkdir -p /var/www/html
RUN chmod +x /usr/local/bin/script.sh
EXPOSE 9000
ENTRYPOINT ["/usr/local/bin/script.sh"]
