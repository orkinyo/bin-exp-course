docker kill $(docker ps -q)
docker rm $(docker ps -a -q)



docker build -t lv22 .
container_id=$(docker run -d -it --rm -p 1026:1026 lv22)
docker cp $container_id:/home/ctf/level22 .
if [ "$1" == "sh" ]; 
then
    docker exec -ituroot $container_id /bin/bash

fi
