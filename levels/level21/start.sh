docker kill $(docker ps -q)
docker rm $(docker ps -a -q)



docker build -t lv21 .
container_id=$(docker run -d -it --rm -p 1025:1025 lv21)

if [ "$1" == "sh" ]; 
then
    docker exec -ituroot $container_id /bin/bash

fi
