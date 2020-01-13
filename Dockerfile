FROM ubuntu

COPY qotd /root/.
COPY Quotes.txt /root/.

WORKDIR /root
CMD ["/root/qotd", "Quotes"]
