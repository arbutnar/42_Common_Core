#!/bin/bash

service mysql start 

#Creating a SQL script db1.sql: In this part, the script generates an SQL script named db1.sql.
#This SQL script contains a series of SQL commands to be executed by the database server.
#The following commands are being generated and written into db1.sql:
echo "CREATE DATABASE IF NOT EXISTS aridb ;" > db1.sql
#So,'$db1_user'@'%' signifies a user named '$db1_user' who has access to the 'db1' database from any host,
#indicating remote access from any location.
echo "CREATE USER IF NOT EXISTS 'ss'@'%' IDENTIFIED BY 'tt' ;" >> db1.sql
echo "GRANT ALL PRIVILEGES ON aridb.* TO 'ss'@'%' ;" >> db1.sql
echo "ALTER USER 'root'@'localhost' IDENTIFIED BY '12345' ;" >> db1.sql
echo "FLUSH PRIVILEGES;" >> db1.sql

# This command executes the SQL script db1.sql against the MySQL or MariaDB server.
# It reads the SQL commands from the script file and applies them to the database.
mysql < db1.sql

#This script use the kill command for simplicity, but in practice,
#database server management should be handled with care to prevent data loss or corruption.
kill $(cat /var/run/mysqld/mysqld.pid)

mysqld