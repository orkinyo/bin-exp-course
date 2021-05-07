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

COPY ./level22.c ./
COPY ./Makefile ./
COPY ./ynetd ./
RUN make

#RUN echo 0 | tee /proc/sys/kernel/randomize_va_space

EXPOSE 1026
RUN chmod +x ./ynetd
USER ctf
CMD ./ynetd -p 1026 ./level22
