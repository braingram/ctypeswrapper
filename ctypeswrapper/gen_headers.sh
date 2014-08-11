#!/bin/bash
gcc -E -P /usr/include/flycapture/C/FlyCapture2_C.h  > full.h
cpp -nostdinc -P /usr/include/flycapture/C/FlyCapture2_C.h  > foo.h
