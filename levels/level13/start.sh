#!/bin/bash
make > /dev/null
LD_PRELOAD="./hook.so" ./level13