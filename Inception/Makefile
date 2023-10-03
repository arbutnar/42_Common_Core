DB = mariadb

mariadb:
	sudo docker build -t $(DB) $(DB)
	sudo docker run --name test $(DB)

clean:
	@chmod 744 clean.sh
	@./clean.sh

.PHONY: nginx wordpress mariadb clean