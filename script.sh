#!/bin/bash

# Initial time
current_date=$(date +%m-%d-%Y)
current_time=$(date | awk '{print $4}')
echo ${current_date}
echo ${current_time}
echo "Start = Start time"
current_start=$current_date@:$current_time


# Global variables
target_name=$1

echo "${target_name}"

# Compilation process
if [ ! -d build ]; then
    mkdir build
fi
cd build/
cmake -S ../ -B .
cmake --build . --target $target_name
cd ../


# Check the target is possible
if [ "${target_name}" != "main" ] && [ "${target_name}" != "tests" ]
then
    echo "Target name wrong. Remind the possibilities are main and tests."
    exit 127

else
    echo "Will execute $target_name"
    # Excution process
    time ./build/$target_name
    rm ./build/$target_name

fi


# Finish time
current_date=$(date +%m-%d-%Y)
current_time=$(date | awk '{print $4}')
echo "Finish = Finish"
echo ${current_date}
echo ${current_time}
current_finish=$current_date@:$current_time

# Difftime
date2sec() { date -d "$(sed 's|-|/|g; s|@| |; s|:| |' <<<"$*")" +%s; }
second=$(echo $(( $(date2sec "$current_finish") - $(date2sec "$current_start") )))
echo "Your bash script needs $second second to process"
