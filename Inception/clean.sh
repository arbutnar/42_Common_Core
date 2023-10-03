#!/bin/bash

#docker-compose -f srcs/docker-compose.yml down
sudo docker stop $(sudo docker ps -qa) 2>/dev/null
sudo docker rm $(sudo docker ps -qa) 2>/dev/null
sudo docker rmi -f $(sudo docker images -qa) 2>/dev/null
#docker volume rm $(docker volume ls -q) 2>/dev/null
#docker network rm $(docker network ls -q) 2>/dev/null
#docker system prune -a --volume 2>/dev/null
sudo docker system prune -a --force 2>/dev/null
#sudo rm -rf /home/bcaffere/ 2>/dev/null