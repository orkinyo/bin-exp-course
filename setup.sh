#!/bin/bash

echo '[+] starting installation'
sudo apt-get update
sudo apt-get -y upgrade
sudo apt-get -y install unattended-upgrades htop fonts-inconsolata git gdb gcc gcc-multilib g++ g++-multilib ltrace linux-source openssh-server python-pip ipython python-dev vim guile-2.0 unzip socat libncurses5-dev texinfo
sudo apt-get install python3 python3-pip python3-dev libssl-dev libffi-dev build-essential -y
python3 -m pip install --upgrade pip
python3 -m pip install --upgrade pwntools
sudo apt-get install gcc-multilib -y
cd ..
git clone https://github.com/pwndbg/pwndbg
cd pwndbg
./setup.sh
cd ../bin-exp-course-Final
sudo apt install docker.io -y
cd ./binary-exploitation-course
sudo echo 0 | sudo tee /proc/sys/kernel/randomize_va_space
sudo echo 'kernel.randomize_va_space = 0' > /etc/sysctl.d/01-disable-aslr.conf
find . -exec chmod +x \{\} \;
sudo groupadd docker
sudo gpasswd -a $USER docker
echo '[+] finished installation'
echo 'you need to login again for docker to work properly without sudo'
gnome-session-quit
