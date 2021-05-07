docker kill $(docker ps -q)
docker rm $(docker ps -a -q)



docker build -t lv20 .
container_id=$(docker run -d -it --rm -p 1024:1024 lv20)

if [ "$1" == "sh" ]; 
then
    docker exec -ituroot $container_id /bin/bash

fi