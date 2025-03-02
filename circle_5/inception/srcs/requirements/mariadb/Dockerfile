FROM debian:11

RUN apt-get update -y \
    && apt-get install -y mariadb-server dumb-init \
    && mkdir -p /run/mysqld \
    && chown -R mysql:mysql /run/mysqld /var/lib/mysql

COPY ./50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf
COPY ./mariadb-init.sh /

EXPOSE 3306

ENTRYPOINT [ "/usr/bin/dumb-init", "--" ]
CMD [ "bash", "/mariadb-init.sh" ]