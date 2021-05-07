FROM ubuntu:16.04

RUN apt-get update && apt-get install -y \
    make \
    build-essential \
    manpages-dev \
    gcc-multilib \
    g++-multilib \
    netcat \
    gdb \
    git-all

RUN git clone https://github.com/longld/peda.git ~/peda
RUN echo "source ~/peda/peda.py" >> ~/.gdbinit



RUN useradd -ms /bin/bash ctf
RUN echo "ctf:ctf" | chpasswd

WORKDIR /home/ctf

COPY ./level21.c ./
COPY ./Makefile ./
COPY ./ynetd ./
RUN make

EXPOSE 1025
RUN chmod +x ./ynetd
USER ctf
CMD ./ynetd -p 1025 ./level21