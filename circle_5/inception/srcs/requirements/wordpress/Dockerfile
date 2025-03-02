FROM debian:11

RUN apt-get update -y \
    && apt-get install dumb-init -y \
    && apt-get install php7.4-fpm php7.4-mysql -y \
    && apt-get install mariadb-client -y \
    && apt-get install curl -y \
    && mkdir -p /var/www/html \
    && chown -R www-data:www-data /var/www/html

COPY ./wordpress-init.sh /

EXPOSE 9000

ENTRYPOINT [ "/usr/bin/dumb-init", "--" ]
CMD [ "bash", "/wordpress-init.sh" ]