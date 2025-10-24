#!/bin/bash
echo "type your massege:"
read message
echo "$message" | nc localhost 8888
