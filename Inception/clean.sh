#!/bin/bash

sudo docker-compose -f src/docker-compose.yml down 2>/dev/null
sudo docker stop $(sudo docker ps -qa) 2>/dev/null
sudo docker rm $(sudo docker ps -qa) 2>/dev/null
sudo docker rmi -f $(sudo docker images -qa) 2>/dev/null
sudo docker volume rm $(sudo docker volume ls -q) 2>/dev/null
sudo rm -rf /home/butna/data/Inception/src/shared
sudo rm -rf /home/butna/data/Inception/src/mariadb/data
sudo docker network rm inception 2>/dev/null
sudo docker system prune -f