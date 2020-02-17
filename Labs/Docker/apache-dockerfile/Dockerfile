FROM httpd
COPY my-httpd.conf /usr/local/apache2/conf/my-httpd.conf
COPY hello.html /usr/local/apache2/htdocs/hello.html
ENV CONTAINER docker
RUN echo $CONTAINER
