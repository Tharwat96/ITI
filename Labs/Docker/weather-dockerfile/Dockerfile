FROM node:alpine

RUN mkdir /node && cd /node && mkdir /node/weather-app

ADD weather.html /node/weather-app

WORKDIR /node/weather-app 

RUN apk add --update npm

LABEL APP_VERSION="2"

ENV NODE_ENV production

RUN cp -r /node/weather-app /var/weather-app

WORKDIR /var/weather-app

EXPOSE 3000

ENTRYPOINT ./bin/www
