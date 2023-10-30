COMPOSE_FILE = ./srcs/docker-compose.yml

all:
	@sudo docker-compose -f $(COMPOSE_FILE) build
	@sudo docker-compose -f $(COMPOSE_FILE) up -d

stop:
	@sudo docker stop $$(sudo docker ps -qa)

clean:
	@sudo docker-compose -f $(COMPOSE_FILE) down
	@sudo docker rmi -f $$(sudo docker images -qa)
	@sudo docker volume rm $$(sudo docker volume ls -q)
	@sudo rm -rf ./srcs/shared/*
	@sudo rm -rf ./srcs/mariadb/data/*
	@sudo docker system prune -f


re: clean all
