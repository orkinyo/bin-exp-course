#!/bin/bash
cd levels
for d in ./*/ ; do (cd "$d" && make -B); done
cd ..