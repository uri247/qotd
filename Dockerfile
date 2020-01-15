FROM ubuntu

COPY qotd /root/.
COPY Quotes.txt /root/.

RUN apt-get update && apt-get install -y \
    net-tools \
    netcat-openbsd \
    telnet

WORKDIR /root
CMD ["/root/qotd", "Quotes"]
