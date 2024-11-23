FROM debian:bullseye-slim


RUN apt-get update && apt-get install -y \
    build-essential \
    librdkafka-dev \
    && rm -rf /var/lib/apt/lists/*


WORKDIR /app/game
COPY ./game .


RUN g++ -std=c++20 -o main main.cpp -I/usr/include -L/usr/lib/x86_64-linux-gnu -lrdkafka++ -lrdkafka

CMD ["./main"]