COMPOSE = src/docker-compose.yml

all:
	mkdir /home/butna/data/Inception/src/shared
	mkdir /home/butna/data/Inception/src/mariadb/data
	@sudo docker-compose -f $(COMPOSE) up -d

clean:
	@chmod 744 clean.sh
	@./clean.sh

re: clean all
