FROM debian:buster

RUN apt-get -y update \
	&& apt-get -y install nginx \
	&& apt-get install libssl-dev \
	&& apt-get install openssl

RUN mkdir /etc/nginx/ssl
RUN openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes \
	-out /etc/nginx/ssl/cert.pem \
	-keyout /etc/nginx/ssl/privkey.key \
	-subj "/C=AM/ST=Yerevan/L=Yerevan/O=42 School/OU=shovsepy/CN=shovsepy/"

COPY ./nginx.conf /etc/nginx/nginx.conf

EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]